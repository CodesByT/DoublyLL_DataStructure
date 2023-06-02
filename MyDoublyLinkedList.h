
#include "DoubyLinkedList.h"
#include "Node.h"

template<class Type>
class MyDoublyLinkedList : public DoublyLinkedlist<Type> {
	Node<Type>* head;
public:
	MyDoublyLinkedList() { head = nullptr; }

	void insertAtFront(Type d);
	void insertAtEnd(Type d);
	void insertNext(Type Nodevalue, Type d);
	void insertSorted(Type d);
	void sortLinkedList();
	void displayList();
	Type removeFromFront();
	Type removeFromEnd();
	Type removeNext(Type Nodevalue);
	Type middleNodeValue();
	int sizeOfList();
	bool isEmpty();
	~MyDoublyLinkedList();
};
