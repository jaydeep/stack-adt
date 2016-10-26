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
		SinglyLinkedList::SinglyLinkedList() //call constructor of base class
	}

	//Copy Constructor
	//Copies one stack onto another
	Stack(const Stack<T>& aStack)
	{

	}

	//Destructor
	~Stack()
	{
		//TODO
	}

	//Behaviors
	//Add a new element to stack.
	//@param	newElement		new element to add
	//@return	void			nothing to return
	void push(const T& newElement)
	{

	}

	//Pop the first element on stack
	//@return returns the popped element
	T& pop()
	{

	}

	//Checks whether stack is empty
	//@return	bool			true if empty, false if not
	bool isEmpty()
	{
		return LinkedList::isEmpty()
	}

	//Prints stack from top to bottom to standard IO
	void printStack()
	{

	}

	//Prints first element of stack
	void printFirst()
	{

	}

	//Gets the total number of elements on stack
	//@return	int		total number of elements on stack
	int getCount()
	{

	}

	//Gets the value of the first element on stack
	//@return	T&		value of first element
	T& getFirst()
	{

	}

	//Gets value of last element on stack
	//@return	T&		value of last element on stack
	T& getLast()
	{

	}

};
#endif