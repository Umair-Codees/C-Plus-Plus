#include <iostream>
using namespace std;

struct node {
	int data;
	node* next;
	node(int value) {
		data = value;
		next = nullptr;
	}
};
class SingllyLinkedList {
	node* head;
	node* tail;
public:
	SingllyLinkedList() {
		head = nullptr;
		tail = nullptr;
	}
	void insertAtHead(int value) {
		node* newNode = new node(value);
		if (head == nullptr && tail == nullptr) {
			head = newNode;
			tail = newNode;
		}
		else {
			newNode->next = head;
			head = newNode;
		}
	}
	void insertAtTail(int value) {
		node* newNode = new node(value);
		if (head == nullptr && tail == nullptr) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
	}
	void deleteAtHead() {
		if (head == nullptr && tail == nullptr) {
			cout << "Linked List is Empty.";
			return;
		}
		else if (head == tail) {
			head = nullptr;
			tail = nullptr;
			return;
		}
		node* temp = head;
		head = temp->next;
		delete temp;
	}
	void deleteAtTail() {
		if (head == nullptr && tail == nullptr) {
			cout << "Linked List is Empty.";
			return;
		}
		else if (head == tail) {
			head = nullptr;
			tail = nullptr;
			return;
		}
		node* temp = head;
		while (temp->next != tail) {
			temp = temp->next;
		}
		delete tail;
		tail = temp;
		tail->next = nullptr;
	}
	void remove(int value) {
		if (head == nullptr && tail == nullptr) {
			cout << "Linked List is Empty.";
			return;
		}
		node* temp = head;
		if (head->data == value) {
			deleteAtHead();
			return;
		}
		else if (tail->data == value) {
			deleteAtTail();
			return;
		}
		while (temp != nullptr && temp->next != nullptr) {
			if (temp->next->data == value) {
				node* toDelete = temp->next;
				temp->next = temp->next->next;
				if (temp->next == nullptr) {
					tail = temp;
				}
				delete toDelete;
				return;
			}
			temp = temp->next;
		}

		cout << "Value Not Found!" << endl;


	}
	void display() {
		node* temp = head;
		if (temp == nullptr) {
			cout << "Linked List is Empty.";
			return;
		}
		while (temp != nullptr) {
			cout << temp->data << " -> ";
			temp = temp->next;
		}
		cout << "nullptr" << endl;
	}
};

int main() {
	SingllyLinkedList sll;

	sll.insertAtHead(2);
	sll.insertAtHead(1);

	sll.display();

	sll.insertAtTail(3);
	sll.insertAtTail(4);

	sll.display();

	sll.deleteAtHead();

	sll.display();

	sll.deleteAtTail();

	sll.display();

	sll.deleteAtHead();

	sll.display();

	sll.deleteAtHead();

	sll.display();

	return 0;
}