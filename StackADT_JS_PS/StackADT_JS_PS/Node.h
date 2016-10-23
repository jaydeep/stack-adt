#ifndef NODE_H
#define NODE_H

template <class T>
class Node
{
protected:
	T item;			//data item
	Node<T> *next;	//pointer to next node

public:
	//Constructors
	Node();
	Node(const T &localItem);
	Node(const T &localItem, Node<T> *nextNodePointer);

	//Mutators
	void setItem(const T &localItem);
	void setNext(Node<T> *nextNodePointer);

	//Accessors
	T getItem() const;
	Node<T> *getNext() const;
};

#endif