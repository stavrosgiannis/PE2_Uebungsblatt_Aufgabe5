/**
 * @file heap.h
 * @brief Enthält die Definition der Klasse "Heap", ihre Attribute und Definitionen der Methoden.
 *
 * Unter "Functions" sind Hilfsfunktionen zu finden, diese sind einfache integer-Berechnungen und haben keinen speziellen Bezug zur Heap-Klasse. Um die Heap-spezifischen Methoden anzuzeigen bitte weiter oben "Classes" -> "Heap<T>" anklicken.
 */

#ifndef PE2_HEAP_H
#define PE2_HEAP_H

#include <iostream>
#include "Exception.h"

using namespace std;

int parent(int i);
int left(int i);
int right(int i);
void swap(int* a, int* b);

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

template <typename T>
Heap<T>::Heap();

template <typename T>
Heap<T>::Heap(T* values, int len);

template <typename T>
Heap<T>::~Heap();

template <typename T>
void Heap<T>::insert(T val);

template <typename T>
T Heap<T>::extractMin();

template <typename T>
char* Heap<T>::toString();

template <typename T>
void Heap<T>::heapify(int root);

template <typename T>
T Heap<T>::minimum();

template <typename T>
void Heap<T>::inc();

template <typename T>
void Heap<T>::dec();

#endif //PE2_HEAP_H
