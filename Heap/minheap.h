#pragma once
#include <iostream>
using namespace std;

class minHeap {
    int* heap;
    int size;
    int current;

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
public:
    minHeap(int s = 5) {
        this->current = 1;
        this->size = s + 1;
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
            delete[] heap;
            heap = temp;
        }
        heap[current] = value;
        heapifyUp(current);
        current++;
    }
    int extractMin() {
        if (current == 1) {
            cout << "Heap is Empty.\n";
            return -1;
        }
        int minVal = heap[1];
        heap[1] = heap[current - 1];
        current--;
        heapifyDown(1);
        return minVal;
    }
    void decreaseKey(int index, int newValue) {
        if (index <= 0 || index >= current) {
            cout << "Invalid Index\n";
            return;
        }
        heap[index] = newValue;
        heapifyUp(index);
    }
    void deleteKey(int index) {
        if (index <= 0 || index >= current) {
            cout << "Invalid Index\n";
            return;
        }
        heap[index] = heap[current - 1];
        current--;
        heapifyDown(index);
    }
    void buildHeap(int arr[], int n) {
        delete[] heap;
        size = n + 1;
        current = n + 1;
        heap = new int[size];

        for (int i = 1; i < current; i++) {
            heap[i] = arr[i - 1];
        }

        for (int i = (current - 1) / 2; i > 0; i--) {
            heapifyDown(i);
        }
    }
    void heapSort() {
        int tempSize = current;
        while (current > 1) {
            swap(heap[1], heap[current - 1]);
            current--;
            heapifyDown(1);
        }
        current = tempSize;
    }
    void display() {
        if (current == 1) {
            cout << "Heap is Empty.\n";
            return;
        }
        for (int i = 1; i < current; i++) {
            cout << heap[i] << "\t";
        }
        cout << endl;
    }
    ~minHeap() {
        delete[] heap;
    }
};
