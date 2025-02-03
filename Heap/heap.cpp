#include <iostream>
#include "minheap.h"
#include "maxheap.h"
using namespace std;

int main() {
	minHeap h1;

	h1.add(2);
	h1.add(1);
	h1.add(3);
	h1.add(4);
	h1.add(5);
	h1.add(0);

	cout << "Heap Before removing: ";
	h1.display();
	cout << endl;

	h1.remove();
	
	cout << "Heap After  removing: ";
	h1.display();
	cout << endl;
	cout << endl;
	cout << endl;

	maxHeap h2;

	h2.add(2);
	h2.add(1);
	h2.add(3);
	h2.add(4);
	h2.add(5);
	h2.add(0);

	cout << "Heap Before removing: ";
	h2.display();
	cout << endl;

	h2.remove();

	cout << "Heap After  removing: ";
	h2.display();
	cout << endl;

	return 0;
}