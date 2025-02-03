#pragma once
#include <iostream>
using namespace std;

class minHeap {
	int* heap;
	int size;
	int current;

	void heapifyUp(int index) {
		while (index > 1) {
			int parent = index / 2;
			if (heap[parent] > heap[index]) {
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

			int smallest = index;
			if (leftChild < current && heap[leftChild] < heap[smallest]) {
				smallest = leftChild;
			}
			if (rightChild < current && heap[rightChild] < heap[smallest]) {
				smallest = rightChild;
			}
			if (smallest != index) {
				swap(heap[index], heap[smallest]);
				index = smallest;
			}
			else {
				break;
			}
		}
	}
public:
	minHeap(int s = 5) {
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
		if (current == 1) {
			cout << "Heap is Empty.";
			return;
		}
		heap[1] = heap[current - 1];
		current--;
		heapifyDown(1);
	}

	void display() {
		for (int i = 0; i < current; i++) {
			cout << heap[i] << "\t";
		}
	}

	~minHeap() {
		delete[] heap;
	}
};