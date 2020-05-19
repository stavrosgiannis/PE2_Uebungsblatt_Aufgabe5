#pragma once
/**
 * @file heap.h
 * @brief Enthält die Definition der Klasse "Heap", ihre Attribute und Definitionen bzw. Implementierungen der Methoden.
 *
 * Unter "Functions" sind Hilfsfunktionen zu finden, diese sind einfache integer-Berechnungen und haben keinen speziellen Bezug zur Heap-Klasse. Um die Heap-spezifischen Methoden anzuzeigen bitte weiter oben "Classes" -> "Heap<T>" anklicken.
 */

#ifndef PE2_HEAP_CPP_HEAP_H
#define PE2_HEAP_CPP_HEAP_H

#include <iostream>
#include "Exception.h"

using namespace std;

/**
 * @brief Hilfsfunktion, um den Index des Elternknotens von einem gegebenen Knoten i zu errechnen
 * @param i Index des Knotens
 * @return int Array-Index, des Elternknotens
 */
int parent(int i) {
	return (i - 1) / 2;
}

/**
 * @brief Hilfsfunktion, um den Index des Linken Kindsknoten eines Elternknotens i zu errechnen
 * @param i Index des Knotens
 * @return int Array-Index, des linken Kindsknoten
 */
int left(int i) {
	return 2 * i + 1;
}

/**
 * @brief Hilfsfunktion, um den Index des rechten Kindsknoten eines Elternknotens i zu errechnen
 * @param i Index des Knotens
 * @return int Array-Index, des rechten Kindsknoten
 */
int right(int i) {
	return 2 * i + 2;
}

/**
 * @brief Hilfsfunktion, um zwei Werte zu tauschen
 * @param *a, *b Pointer auf die zu tauschenden Werte
 */
void swap(int* a, int* b) {
	int buf;
	buf = *a;
	*a = *b;
	*b = buf;
}

/**
 * @brief Heap-Klasse
 */
template <typename T>
class Heap {
private:
	T* _val;                            /**< Dynamisches typenloses Array, in dem alle Elemente des Heaps gespeichert werden.*/
	int _size, _next;                   /**< _Size gibt die Gesamtgröße des Arrays *_val an. _next ist der Index des nächsten Elementes im Array *_val.*/

	void heapify(int root);
	T minimum();
	void inc();
	void dec();

public:
	Heap(); //Standard-Konstruktor
	Heap(T* values, int len);
	~Heap();        //Destruktor

	void insert(T val);
	T extractMin();
	char* toString();
};

/**
 * @brief Standard-Konstruktor der Klasse Heap.
 *
 * Der Standardkonstruktor erwartet keine Übergabeparameter. Die Größe des Arrays wird initial auf 8 Elemente gesetzt. Das Array ist zunächst leer.
 * */
template <typename T>
Heap<T>::Heap() : _next(0), _size(8) {
	_val = new T[_size];
}

/**
 * @brief Konstruktor der Klasse Heap.
 *
 * Mit diesem Konstruktor kann der erzeugte Heap direkt mit einem vorhandenen Array gefüllt werden. Die Größe des Arrays wird initial auf 8 gesetzt und nur bei Bedarf erweitert.
 * @param values Pointer auf Array, in dem die Werte gespeichert sind, mit welchem der Heap initialisiert werden soll.
 * @param len Länge des übergebenen Arrays.
 */
template <typename T>
Heap<T>::Heap(T* values, int len) : _next(0), _size(8) {
	_val = new T[_size];
	for (int i = 0; i < len; i++) {
		insert(values[i]);
	}
}

/**
 * @brief Destruktor der Klasse Heap.
 *
 * Gibt den reservierten Speicherplatz des Heap-Arrays frei.
 */
template <typename T>
Heap<T>::~Heap() {
	delete[] _val;
}

/**
 * @brief Fügt einen Wert val in den Heap ein. Anschließend werden die Heap-Bedingungen wiederhergestellt.
 * @param val Einzufügender Wert
 */
template <typename T>
void Heap<T>::insert(T val) {
	if (_next + 1 >= _size) inc();

	_val[_next] = val;

	int i = _next;

	while (i != 0 && _val[parent(i)] > _val[i]) {
		swap(&_val[parent(i)], &_val[i]);
		i = parent(i);
	}

	_next++;
}

/**
 * @brief Extrahiert den Root-Wert des Heaps.
 *
 * Nachdem der Wert extrahiert wurde werden die Heap-Bedingungen des gesamten Heaps mithilfe von heapify() wiederhergestellt
 * @return root-Wert
 */
template <typename T>
T Heap<T>::extractMin() {
	try {
		T min = minimum();
		_val[0] = _val[_next];
		_next--;
		heapify(0);

		if (_size > 8 && _next <= _size / 4) dec();

		return min;
	}
	catch (Exception e) {
		cout << e.toString() << endl;
	}
};

/**
 * @brief Wandelt den Inhalt des Heaps in einen ausgabefreundlichen String um.
 * @return String bestehend aus den Werten des Heaps.
 */
template <typename T>
char* Heap<T>::toString() {
	char* string;
	int i, n = 0;

	string = new char[_next + 1 * sizeof(char)];

	for (i = 0; i < _next; i++)
		n += sprintf(&string[n], "%i ", _val[i]);

	return string;
};

/**
 * @brief Stellt die Heap-Bedingungen des Heaps ab der gegebenen Wurzel root wieder her.
 * @param root Wurzel, ab welcher heapify ausgeführt werden soll.
 */
template <typename T>
void Heap<T>::heapify(int root) {
	int i = root;
	do {
		int min = i;
		if (left(i) < _next && _val[left(i)] < _val[min]) min = left(i);
		if (right(i) < _next && _val[right(i)] < _val[min]) min = right(i);
		if (min == i) break;
		swap(&_val[i], &_val[min]);
		i = min;
	} while (true);
}

/**
 * @brief Gibt den root-Wert des Heaps zurück. Im Gegensatz zu extractMin() wird dieser Wert jedoch nicht aus dem Heap entfernt.
 * @return Min-Wert/root-Wert des Heaps
 */
template <typename T>
T Heap<T>::minimum() {
	if (_next <= 0) {
		throw Exception("Error: tried to get minimum from empty heap");
	}
	return (_val[0]);
}

/**
 * @brief Hilfsfunktion um das Heap-Array um das doppelte zu vergrößern.
 */
template <typename T>
void Heap<T>::inc() {
	T* buf = new T[_size * 2];

	for (int i = 0; i < _size; i++)
		buf[i] = _val[i];

	delete[] _val;
	_val = buf;
	_size *= 2;
}

/**
 * @brief Hilfsfunktion um das Heap-Array zu halbieren.
 */
template <typename T>
void Heap<T>::dec() {
	T* buf = new T[_size / 2];

	for (int i = 0; i < _size / 2; i++)
		buf[i] = _val[i];

	delete[] _val;
	_val = buf;
	_size /= 2;
}

#endif //PE2_HEAP_CPP_HEAP_H
