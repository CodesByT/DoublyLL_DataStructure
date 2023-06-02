#include "Node.h"

template<class Type>
Node<Type>::Node() { 
	Data = NULL; Next = nullptr; Prev = nullptr;
}
template<class Type>
Type Node<Type>::getData() { 
	return Data;
}
template<class Type>
Node<Type>* Node<Type>::getNext() {
	return Next;
}
template<class Type>
Node<Type>* Node<Type>::getPrev() { 
	return Prev; 
}
template<class Type>
void Node<Type>::setData(Type d) { 
	Data = d;
}
template<class Type>
void Node<Type>::setNext(Node<Type>* n) {
	Next = n; 
}
template<class Type>
void Node<Type>::setPrev(Node<Type>* p) {
	Prev = p;
}
template<class Type>
Node<Type>::~Node() { 
	cout << "...Node Destructor...\n";
}