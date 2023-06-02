#include "MyDoublyLinkedList.h"

template<class Type>
MyDoublyLinkedList<Type>::MyDoublyLinkedList() {
	head = nullptr;
}
template<class Type>
void MyDoublyLinkedList<Type>::insertAtFront(Type d) {
	Node<Type>* newnode = new Node<Type>;
	newnode->setData(d);
	if (head == nullptr)
		head = newnode;
	else {
		newnode->setNext(head);
		head->setPrev(newnode);
		head = newnode;
	}
}
template<class Type>
void MyDoublyLinkedList<Type>::insertAtEnd(Type d) {
	Node<Type>* newnode = new Node<Type>;
	newnode->setData(d);
	if (head == nullptr)
		head = newnode;
	else {
		Node<Type>* temp = head;
		while (temp->getNext() != nullptr) {
			temp = temp->getNext();
		}
		temp->setNext(newnode);
		newnode->setPrev(temp);

	}
}
template<class Type>
void MyDoublyLinkedList<Type>::insertNext(Type Nodevalue, Type d) {
	Node<Type>* newnode = new Node<Type>;
	newnode->setData(d);
	Node<Type>* temp = head;
	while (temp->getData() != d) {
		temp = temp->getNext();
	}
	newnode->setNext(temp->getNext());
	newnode->setPrev(temp);
	temp->getNext()->setPrev(newnode);
	temp->setNext(newnode);
}
template<class Type>
void MyDoublyLinkedList<Type>::insertSorted(Type d) {
	Node<Type>* temp = head;
	Node<Type>* prev = nullptr;
	while (temp->getData() < d && temp->getNext() != nullptr) {
		prev = temp;
		temp = temp->getNext();
	}
	if (head == temp) {
		insertAtFront(d);
	}
	else if (temp->getData() < d && temp->getNext() == nullptr) {
		insertAtEnd(d);
	}
	else {
		Node<Type>* newnode = new Node<Type>;
		newnode->setData(d);
		newnode->setNext(temp);
		prev->setNext(newnode);
		newnode->setPrev(prev);
		prev->getNext()->setPrev(newnode);
	}
}
template<class Type>
void MyDoublyLinkedList<Type>::sortLinkedList() {
	Node<Type>* outer = head;
	Node<Type>* inner;
	while (outer != nullptr) {
		inner = outer->getNext();
		while (inner != nullptr) {
			if (outer->getData() > inner->getData()) {
				Type data = outer->getData();
				outer->setData(inner->getData());
				inner->setData(data);
			}
			inner = inner->getNext();
		}
		outer = outer->getNext();
	}
}
template<class Type>
void MyDoublyLinkedList<Type>::displayList() {
	Node<Type>* temp = head;
	cout << "\nDoubly LinkedList = HEAD";
	while (temp != nullptr) {
		cout << " <-> " << temp->getData();
		temp = temp->getNext();
	}
	cout << "\n";
}
template<class Type>
Type MyDoublyLinkedList<Type>::removeFromFront() {
	Node<Type>* nodeDestruct = head;
	head = head->getNext();
	head->setPrev(nullptr);
	Type data = nodeDestruct->getData();
	delete nodeDestruct;
	return data;
}
template<class Type>
Type MyDoublyLinkedList<Type>::removeFromEnd() {
	if (isEmpty()) {
		cout << "List is empty.\n";
		return Type();
	}

	Node<Type>* temp = head;
	while (temp->getNext() != nullptr) {
		temp = temp->getNext();
	}

	if (temp->getPrev() != nullptr) {
		temp->getPrev()->setNext(nullptr);
	}
	else {
		head = nullptr;
	}

	Type data = temp->getData();
	delete temp;
	return data;
}
template<class Type>
Type MyDoublyLinkedList<Type>::removeNext(Type Nodevalue) {
	if (isEmpty()) {
		cout << "List is empty.\n";
		return Type();
	}

	Node<Type>* temp = head;
	while (temp != nullptr && temp->getData() != Nodevalue) {
		temp = temp->getNext();
	}

	if (temp == nullptr || temp->getNext() == nullptr) {
		cout << "Node with value " << Nodevalue << " not found or next node is null.\n";
		return Type();
	}

	Node<Type>* nodeDestruct = temp->getNext();
	temp->setNext(temp->getNext()->getNext());
	if (temp->getNext() != nullptr) {
		temp->getNext()->setPrev(temp);
	}

	Type data = nodeDestruct->getData();
	delete nodeDestruct;
	return data;
}
template<class Type>
Type MyDoublyLinkedList<Type>::middleNodeValue() {
	Node<Type>* temp1 = head;
	Node<Type>* temp2 = head; int a = 0;
	while (temp1 != nullptr && temp1->getNext() != nullptr) {
		temp1 = temp1->getNext()->getNext();
		temp2 = temp2->getNext();
		a++; cout << "wot";
	}
	temp2 = temp2->getPrev();
	cout << "\nNode number ' " << a << " ' is middle and\n";
	cout << "Middle Node value is = " << temp2->getData() << endl;
	return temp2->getData();
}
template<class Type>
int MyDoublyLinkedList<Type>::sizeOfList() {
	Node<Type>* temp2 = head; int a = 0;
	while (temp2 != nullptr) {
		temp2 = temp2->getNext(); a++;
	}
	return a;
}
template<class Type>
bool MyDoublyLinkedList<Type>::isEmpty() {
	return(head == nullptr ? 1 : 0);
}
template<class Type>
MyDoublyLinkedList<Type>::~MyDoublyLinkedList() {  }
