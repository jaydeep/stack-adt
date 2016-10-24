#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include "Node.h"

//implementation is in .h file as opposed to separate .cpp file to avoid linker error due to use of templates
//refer to https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl
//to be implemented: exception handling (out of bounds behaviors)

template <class T>
class SinglyLinkedList
{
private:
	Node<T> *headPointer;	//pointer to first node in chain
	Node<T> *tailPointer;	//pointer to last node in chain

	int itemCount;					//current count of list items

	//Locates a specified node in a linked list
	//@pre					position is the number of the desired node;
	//						position >= 1 and position <= itemCount.
	//@post					the node is found and a pointer to it is returned.
	//@param	position	The number of the node to locate.
	//@return				a pointer to the node at the given position.
	Node<T> *getNodeAt(int position) const
	{
		//Counting from the beginning of the chain
		Node<T> *currentPointer = headPointer;
		for (int i = 1; i < position; i++)
		{
			currentPointer = currentPointer->getNext();
		}
		return currentPointer;
	}

public:
	//Constructor
	SinglyLinkedList()
	{
		headPointer = nullptr;
		tailPointer = nullptr;
		itemCount = 0;
	}

	//Copy Constructor
	SinglyLinkedList(const SinglyLinkedList<T>& aList)
	{
		itemCount = aList.itemCount;

		//pointer to node in original chain
		Node<T>* originalChainPointer = aList.headPointer;
		
		//original chain is empty
		if (originalChainPointer == nullptr)
		{
			headPointer = nullptr;
		}

		//original chain is not empty
		else
		{
			//copying first node
			headPointer = new Node<T>();
			headPointer->setItem(originalChainPointer->getItem());

			//pointer for first node in new chain
			Node<T>* newChainPointer = headPointer;

			//copying remaining nodes
			for (int i = 1; i < itemCount; i++)
			{
				//advancing original chain pointer
				originalChainPointer = originalChainPointer->getNext();
				
				//getting next item from original chain
				T nextItem = originalChainPointer->getItem();

				//creating a new node to contain the next item
				Node<T> *newNodePointer = new Node<T>(nextItem);

				//linking new node to end of new chain
				newChainPointer->setNext(newNodePointer);

				//advancing pointer to new last node
				newChainPointer = newChainPointer->getNext();
			}

			//flagging end of chain
			newChainPointer->setNext(nullptr);
		}

		//setting tail pointer
		tailPointer = aList.tailPointer;
	}

	//Destructor
	~SinglyLinkedList()
	{
		clear();
	}

	//Methods
	//Checks if list is empty
	bool isEmpty() const
	{
		return itemCount == 0;
	}

	//Gets the length of the list
	int getLength() const
	{
		return itemCount;
	}

	//Inserts a new entry
	bool insert(int newPosition, const T& newEntry)
	{
		//Variable to check if position to add to is within bounds
		bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);

		if (ableToInsert)
		{
			//Creating a new node containing the new entry
			Node<T>* newNodePointer = new Node<T>(newEntry);

			//Adding new node to beginning of chain
			if (newPosition == 1)
			{
				newNodePointer->setNext(headPointer);
				headPointer = newNodePointer;
				tailPointer = getNodeAt(itemCount);
			}

			//Adding new node elsewhere in chain
			else
			{
				//Finding node that will be before new node
				Node<T>* previousPointer = getNodeAt(newPosition - 1);

				//Inserting new node after previousPointer's node
				newNodePointer->setNext(previousPointer->getNext());
				previousPointer->setNext(newNodePointer);

				//Setting tail pointer
				tailPointer = getNodeAt(itemCount+1);
			}

			//Increment count of entries
			itemCount++;
		}

		return ableToInsert;
	}

	//Removes an entry
	bool remove(int position)
	{
		//Temporary pointer for deallocation of allocated memory for removed nodes
		Node<T>* currentPointer = nullptr;
		
		//Variable to check if position to remove is within bounds
		bool ableToRemove = (position >= 1) && (position <= itemCount);

		if (ableToRemove)
		{
			//Removing node at beginning of chain
			if (position == 1)
			{
				//pointer to node to be removed must be saved in some temporary pointer in order to release memory allocated for removed node
				currentPointer = headPointer;
				headPointer = headPointer->getNext();
			}

			//Removing node elsewhere in chain
			else
			{
				//Finding node before the node to delete
				Node<T>* previousPointer = getNodeAt(position - 1);

				//Pointing to node to delete
				currentPointer = previousPointer->getNext();

				//Removing node from chain by connecting the previous node to the node after the removed node
				previousPointer->setNext(currentPointer->getNext());
			}

			//Releasing memory allocated for removed node
			currentPointer->setNext(nullptr);
			delete currentPointer;
			currentPointer = nullptr;

			//Decrementing count of entries
			itemCount--;
		}
		
		return ableToRemove;
	}
	
	//Clears the list
	void clear()
	{
		while (!isEmpty())
		{
			remove(1);
		}
	}

	//Gets an entry
	T getEntry(int position)
	{
		//Variable to check if position of entry to get is within bounds
		bool ableToGet = (position >= 1) && (position <= itemCount);
		
		if (ableToGet)
		{
			Node<T>* entryNodePointer = getNodeAt(position);
			return entryNodePointer->getItem();
		}
	}

	//Sets an entry
	void setEntry(int position, const T& newEntry)
	{
		//Variable to check if position of entry to set is within bounds
		bool ableToSet = (position >= 1) && (position <= itemCount);

		if (ableToSet)
		{
			Node<T>* entryNodePointer = getNodeAt(position);
			entryNodePointer->setItem(newEntry);
		}
	}


};

#endif