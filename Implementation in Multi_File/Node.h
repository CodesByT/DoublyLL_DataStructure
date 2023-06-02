#pragma once
template<class Type>
class Node {
	Type Data;
	Node<Type>* Next;
	Node<Type>* Prev;
public:
	Node();
	Type getData();
	Node<Type>* getNext();
	Node<Type>* getPrev();
	void setData(Type d);
	void setNext(Node<Type>* n);
	void setPrev(Node<Type>* p);
	~Node();
};
