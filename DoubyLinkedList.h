#pragma once
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

