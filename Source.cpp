#include "MyDoublyLinkedList.h"
#include<iostream>
using namespace std;

int main() {
	MyDoublyLinkedList<int> list;

	list.insertAtFront(9);
	list.displayList();

	list.insertAtFront(3);
	list.insertAtFront(4);
	list.insertAtFront(9);
	list.displayList();

	list.insertAtEnd(5);
	list.insertAtEnd(7);
	list.insertAtEnd(2);
	list.displayList();

	list.insertSorted(1);
	list.displayList();

	list.insertSorted(69);
	list.displayList();
	list.middleNodeValue();

	list.insertSorted(4);
	list.displayList();

	list.sortLinkedList();
	list.displayList();

	cout << list.removeFromFront() << endl;
	list.displayList();

	cout << list.removeFromEnd() << endl;
	list.displayList();

	cout << list.removeNext(4) << endl;
	list.displayList();

	cout << list.sizeOfList() << endl;

	list.insertAtFront(3);
	list.displayList();
	list.middleNodeValue();
	cout << "\n\n\n";
	return 0;
}