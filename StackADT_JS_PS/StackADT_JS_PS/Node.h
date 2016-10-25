#ifndef NODE_H
#define NODE_H

//implementation is in .h file as opposed to separate .cpp file to avoid linker error due to use of templates
//refer to https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl

template <class T>
class Node
{
protected:
	T item;			//data item
	Node<T> *next;	//pointer to next node (if headNode, pointer to head)

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