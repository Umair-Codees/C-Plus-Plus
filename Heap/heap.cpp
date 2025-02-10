#include <iostream>
#include "minheap.h"
#include "maxheap.h"
using namespace std;

int main() {
    minHeap h1(10);

    h1.add(10);
    h1.add(20);
    h1.add(15);
    h1.add(30);
    h1.add(40);
    h1.add(50);
    h1.add(5);

    cout << "Heap after insertions: ";
    h1.display();

    cout << "\nExtracted Min: " << h1.extractMin() << endl;
    h1.display();

    h1.decreaseKey(3, 2);
    cout << "\nHeap after decreasing key at index 3 to 2: ";
    h1.display();

    h1.deleteKey(2);
    cout << "\nHeap after deleting index 2: ";
    h1.display();

    int arr1[] = { 35, 20, 15, 5, 10 };
    h1.buildHeap(arr1, 5);
    cout << "\nHeap built from array: ";
    h1.display();

    h1.heapSort();
    cout << "\nHeap after Heap Sort: ";
    h1.display();

    maxHeap h2(10);

    h2.add(50);
    h2.add(30);
    h2.add(20);
    h2.add(15);
    h2.add(10);
    h2.add(8);
    h2.add(16);

    cout << "\nHeap after insertions: ";
    h2.display();

    cout << "Extracted Max: " << h2.extractMax() << endl;
    h2.display();

    h2.increaseKey(3, 60);
    cout << "\nHeap after increasing key at index 3 to 60: ";
    h2.display();

    h2.deleteKey(2);
    cout << "\nHeap after deleting index 2: ";
    h2.display();

    int arr2[] = { 40, 20, 10, 5, 15 };
    h2.buildHeap(arr2, 5);
    cout << "\nHeap built from array: ";
    h2.display();

    h2.heapSort();
    cout << "\nHeap after Heap Sort: ";
    h2.display();

	return 0;
}
