#include "Node.h"

//Constructors
template <class T> 
Node<T>::Node()
{
	next = nullptr;
}

template <class T> 
Node<T>::Node(const T &localItem)
{
	item = localItem;
	next = nullptr;
}

template <class T> 
Node<T>::Node(const T &localItem, Node<T> *nextNodePointer)
{
	item = localItem;
	next = nextNodePointer;
}

//Mutators
template <class T>
void Node<T>::setItem(const T &localItem)
{
	item = localItem;
}

template <class T>
void Node<T>::setNext(Node<T> *nextNodePointer)
{
	next = nextNodePointer;
}

//Accessors
template <class T>
T Node<T>::getItem() const
{
	return item;
}

template <class T>
Node<T> *Node<T>::getNext() const
{
	return next;
}