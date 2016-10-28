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
		SinglyLinkedList::SinglyLinkedList(aStack)
		cout << "copied stack" << endl;
	}

	//Destructor
	~Stack()
	{
		SinglyLinkedList::~SinglyLinkedList
		cout << "destroyed stack" << endl;
	}

	//Behaviors
	//Add a new element to stack.
	//@param	newElement		new element to add
	//@return	void			nothing to return
	bool push(const T& newElement)
	{
		return SinglyLinkedList::insert(newElement);	
	}

	//Pop the first element on stack
	//@return returns the popped element
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
		for (int i = 1; i < getCount; i++;)
		{
			cout << getEntry(i);
		}
	}

	//Prints first element of stack
	void printFirst()
	{
		cout << getFirst << endl;
	}

	//Gets the total number of elements on stack
	//@return	int		total number of elements on stack
	int getCount()
	{
		return SinglyLinkedList::getLength();
	}

	//Gets value of last element on stack
	//@return	T&		value of last element on stack
	T& getLast()
	{
		return SinglyLinkedList::getEntry(headNode.getItemCount());
	}

};
#endif
