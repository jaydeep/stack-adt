#ifndef STACK_H
#define STACK_H

#include "SinglyLinkedList.h"

template <class T>
class Stack : protected SinglyLinkedList <T>
{
protected:
	//No data members needed, inherited from SinglyLinkedList

public:
	//Constructors
	//Creates an empty stack
	Stack()
	{
		SinglyLinkedList::SinglyLinkedList(); //call constructor of base class
	}

	//Copy Constructor
	//Copies one stack onto another
	Stack(const Stack<T>& aStack)
	{
		SinglyLinkedList::SinglyLinkedList(aStack);
	}

	//Destructor is not necessary because it will automatically be called in reverse
	//chain of inheritance

	//Behaviors
	//Add a new element to stack.
	//@param	newElement		new element to add
	//@return	bool			true if element is added
	bool push(const T& newElement)
	{
		return SinglyLinkedList::insertFirst(newElement);
	}

	//Pop the first element on stack
	//@return true if element is successfully popped
	bool pop()
	{
		return SinglyLinkedList::removeFirst();
	}

	//Checks whether stack is empty
	//@return	bool			true if empty, false if not
	bool isEmpty()
	{
		return SinglyLinkedList::isEmpty();
	}

	//Prints stack from top to bottom to standard IO
	void printStack()
	{
		for (int i = 1; i < getCount()+1; i++)
		{
			cout << getEntry(i) << endl;
		}
	}

	//Prints first element of stack
	void printFirst()
	{
		cout << getFirst() << endl;
	}

	//Gets the total number of elements on stack
	//@return	int		total number of elements on stack
	int getCount()
	{
		return SinglyLinkedList::getLength();
	}

	T getFirst()
	{
		return SinglyLinkedList::getEntry(1);
	}

	//Gets value of last element on stack
	//@return	T&		value of last element on stack
	T getLast()
	{
		return SinglyLinkedList::getEntry(headNode.getItemCount());
	}

};
#endif