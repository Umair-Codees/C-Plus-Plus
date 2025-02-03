#pragma once
#pragma once
#include <iostream>
using namespace std;

class maxHeap {
	int* heap;
	int size;
	int current;

	void heapifyUp(int index) {
		while (index > 1) {
			int parent = index / 2;
			if (heap[parent] < heap[index]) {
				swap(heap[parent], heap[index]);
				index = parent;
			}
			else {
				break;
			}
		}
	}

	void heapifyDown(int index) {
		while (index * 2 < current) {
			int leftChild = index * 2;
			int rightChild = index * 2 + 1;

			int largest = index;
			if (leftChild < current && heap[leftChild] > heap[largest]) {
				largest = leftChild;
			}
			if (rightChild < current && heap[rightChild] > heap[largest]) {
				largest = rightChild;
			}
			if (largest != index) {
				swap(heap[index], heap[largest]);
				index = largest;
			}
			else {
				break;
			}
		}
	}
public:
	maxHeap(int s = 5) {
		this->current = 1;
		this->size = s;
		heap = new int[size];
		heap[0] = -1;
	}

	void add(int value) {
		if (current == size) {
			size *= 2;
			int* temp = new int[size];
			for (int i = 0; i < current; i++) {
				temp[i] = heap[i];
			}
			delete[]heap;
			heap = temp;
		}

		int index = current;
		heap[index] = value;
		current++;
		heapifyUp(index);
	}

	void remove() {
		heap[1] = heap[current];

	}

	void display() {
		for (int i = 0; i < current; i++) {
			cout << heap[i] << "\t";
		}
	}

	~maxHeap() {
		delete[] heap;
	}
};