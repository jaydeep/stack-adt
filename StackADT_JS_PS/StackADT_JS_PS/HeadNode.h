#ifndef HEAD_NODE_H
#define HEAD_NODE_H

#include "Node.h"

//implementation is in .h file as opposed to separate .cpp file to avoid linker error due to use of templates
//refer to https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl

template <class T>
class HeadNode : public Node <T>
{
protected:
	int ItemCount;		//item count	//wanted to use "item" member from Node class to hold count of items, but this does not work if Node is of type string

	Node<T> *last;		//pointer to last node

public:
	//Constructors
	HeadNode()
	{
		ItemCount = 0;
		last = nullptr;
	}

	HeadNode(const int &localItemCount)
	{
		ItemCount = localItemCount;
	}

	HeadNode(const int &localItemCount, Node<T> *headPointer)
	{
		ItemCount = localItemCount;
		next = headPointer;
	}

	HeadNode(const int &localItemCount, Node<T> *headPointer, Node<T> *tailPointer)
	{
		ItemCount = localItemCount;
		next = headPointer;
		last = tailPointer;
	}

	//Mutators
	void setItemCount(const int &localItemCount)
	{
		ItemCount = localItemCount;
	}

	void setLast(Node<T> *tailPointer)
	{
		last = tailPointer;
	}

	//Accessors
	int getItemCount() const
	{
		return ItemCount;
	}

	Node<T> *getLast() const
	{
		return last;
	}
};

#endif