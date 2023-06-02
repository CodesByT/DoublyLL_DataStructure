#include<iostream>
using namespace std;
template<class Type>
class Node {
	Type Data;
	Node<Type>* Next;
	Node<Type>* Prev;
public:
	Node() { Data = NULL; Next = nullptr; Prev = nullptr; }
	Type getData() { return Data; }
	Node<Type>* getNext() { return Next; }
	Node<Type>* getPrev() { return Prev; }
	void setData(Type d) { Data = d; }
	void setNext(Node<Type>* n) { Next = n; }
	void setPrev(Node<Type>* p) { Prev = p; }
	~Node() { cout << "...Node Destructor...\n"; }
};
template<class Type>
class DoublyLinkedlist {
public:
	virtual void insertAtFront(Type) = 0;
	virtual void insertAtEnd(Type) = 0;
	virtual void insertNext(Type Nodevalue, Type) = 0;
	virtual void insertSorted(Type) = 0;
	virtual void sortLinkedList() = 0;
	virtual Type removeFromFront() = 0;
	virtual Type removeNext(Type) = 0;
	virtual Type removeFromEnd() = 0;
};
template<class Type>
class MyDoublyLinkedList : public DoublyLinkedlist<Type> {
	Node<Type>* head;
public:
	MyDoublyLinkedList() { head = nullptr; }

	void insertAtFront(Type d) {
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
	void insertAtEnd(Type d) {
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
	void insertNext(Type Nodevalue, Type d) {
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
	void insertSorted(Type d) {
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
	void sortLinkedList() {
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
	void displayList() {
		Node<Type>* temp = head;
		cout << "\nDoubly LinkedList = HEAD";
		while (temp != nullptr) {
			cout << " <-> " << temp->getData();
			temp = temp->getNext();
		}
		cout << "\n";
	}
	Type removeFromFront() {
		Node<Type>* nodeDestruct = head;
		head = head->getNext();
		head->setPrev(nullptr);
		Type data = nodeDestruct->getData();
		delete nodeDestruct;
		return data;
	}

	Type removeFromEnd() {
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

	Type removeNext(Type Nodevalue) {
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
	Type middleNodeValue() {
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
	int sizeOfList() {
		Node<Type>* temp2 = head; int a = 0;
		while (temp2 != nullptr) {
			temp2 = temp2->getNext(); a++;
		}
		return a;
	}
	bool isEmpty(){ return(head == nullptr ? 1 : 0); }
	~MyDoublyLinkedList() {  }
};
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
