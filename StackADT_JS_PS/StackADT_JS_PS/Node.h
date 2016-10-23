#ifndef NODE_H
#define NODE_H

//implementation is in .h file as opposed to separate .cpp file to avoid linker error
//refer to http://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file

template <class T>
class Node
{
protected:
	T item;			//data item
	Node<T> *next;	//pointer to next node

public:
	//Constructors
	Node()
	{
		next = nullptr;
	}
	Node(const T &localItem)
	{
		item = localItem;
		next = nullptr;
	}
	Node(const T &localItem, Node<T> *nextNodePointer)
	{
		item = localItem;
		next = nextNodePointer;
	}

	//Mutators
	void setItem(const T &localItem)
	{
		item = localItem;
	}

	void setNext(Node<T> *nextNodePointer)
	{
		next = nextNodePointer;
	}

	//Accessors
	T getItem() const
	{
		return item;
	}

	Node<T> *getNext() const
	{
		return next;
	}
};

#endif