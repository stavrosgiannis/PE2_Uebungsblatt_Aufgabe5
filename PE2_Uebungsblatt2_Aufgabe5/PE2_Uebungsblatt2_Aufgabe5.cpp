/**
 * @file main.cpp
 * @brief Testprogramm
 *
 * Test 1 fügt mit insert() 20 Werte in den Heap ein. Anschließend wird 20 mal extractMin() auf den Heap ausgeführt. Der Test ist erfolgreich, wenn kein Fehler auf der Konsole ausgegeben wurde.
 * Test 2 funktioniert wie Test 1. Allerdings wird der Heap nicht mithilfe von insert() gefüllt, sondern direkt mit einem Array initialisiert. Auch hier gilt: der Test ist erfolgreich, wenn kein Fehler auf der Konsole ausgegeben wurde.
 */

#include <iostream>
#include "heap.cpp"
#include <ctime>

using namespace std;

int main() {
	srand(time(NULL));

	//Test 1
	Heap<int> h;

	for (int i = 0; i < 20; i++) {
		h.insert(rand() % 100);
	}

	for (int i = 0; i < 20; i++) {
		h.extractMin();
	}

	cout << "Test 1 finished" << endl << endl;

	//Test 2
	int* values = new int[20];

	for (int i = 0; i < 20; i++) {
		values[i] = rand() % 100;
	}

	Heap<int> l(values, 20);

	for (int i = 0; i < 20; i++) {
		l.extractMin();
	}

	cout << "Test 2 finished" << endl << endl;
}