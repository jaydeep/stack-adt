#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include "Node.h"
#include "HeadNode.h"

//implementation is in .h file as opposed to separate .cpp file to avoid linker error due to use of templates
//refer to https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl

template <class T>
class SinglyLinkedList
{
protected:
	HeadNode<T> headNode;

	//Locates a specified node in a linked list, for internal use only
	//@pre					position is the number of the desired node;
	//						position >= 1 and position <= itemCount
	//@post					the node is found and a pointer to it is returned
	//@param	position	the number of the node to locate
	//@return				a pointer to the node at the given position
	Node<T> *getNodeAt(int position) const
	{
		//Counting from the beginning of the chain
		Node<T> *currentPointer = headNode.getNext();
		for (int i = 1; i < position; i++)
		{
			currentPointer = currentPointer->getNext();
		}
		return currentPointer;
	}

public:
	//Constructor
	//creates an empty list
	SinglyLinkedList()
	{
		headNode.setNext(nullptr);
		headNode.setLast(nullptr);
		headNode.setItemCount(0);
	}

	//Copy Constructor
	//copies one list into another
	SinglyLinkedList(const SinglyLinkedList<T>& aList)
	{
		//pointer to node in original chain
		Node<T>* originalChainPointer = aList.headNode.getNext();

		//item count
		headNode.setItemCount(aList.headNode.getItemCount());

		//original chain is empty
		if (originalChainPointer == nullptr)
		{
			//nothing
		}

		else
		{
			//copy first node
			headNode.setNext(new Node<T>());
			this->setEntry(1, originalChainPointer->getItem());

			//copy remaining nodes
			Node<T>* newChainPointer = headNode.getNext();	//last-node pointer

			for (int i = 1; i < headNode.getItemCount(); i++)
			{
				//advancing original chain pointer
				originalChainPointer = originalChainPointer->getNext();

				//getting next item from original chain
				T nextItem = originalChainPointer->getItem();

				//creating a new node to contain the next item
				Node<T>* newNodePointer = new Node<T>(nextItem);

				//linking new node to end of new chain
				newChainPointer->setNext(newNodePointer);

				//advancing pointer to new last node
				newChainPointer = newChainPointer->getNext();
			}

			//flagging end of chain
			newChainPointer->setNext(nullptr);

			//setting tail pointer
			headNode.setLast(newChainPointer);

		}
	}

	//Destructor
	~SinglyLinkedList()
	{
		clear();
	}

	//Methods
	//Checks if list is empty
	//@return	true if list is empty
	bool isEmpty() const
	{
		return (headNode.getItemCount() == 0);
	}

	//Gets the length of the list
	//@return	integer value for number of entries in the list
	int getLength() const
	{
		return (headNode.getItemCount());
	}

	//Inserts a new entry
	//@param	newPosition		position to add new entry to
	//@param	newEntry		new entry
	//@return					true if newPosition is valid and newEntry successfully added
	bool insert(int newPosition, const T& newEntry)
	{
		//Variable to check if position to add to is within bounds
		bool ableToInsert = (newPosition >= 1) && (newPosition <= (headNode.getItemCount()) + 1);

		if (ableToInsert)
		{
			//Creating a new node containing the new entry
			Node<T>* newNodePointer = new Node<T>(newEntry);

			//Adding new node to beginning of chain
			if (newPosition == 1)
			{
				newNodePointer->setNext(headNode.getNext());
				headNode.setNext(newNodePointer);
				headNode.setLast(getNodeAt(headNode.getItemCount()));
			}

			//Adding new node elsewhere in chain
			else
			{
				//Finding node that will be before new node
				Node<T>* previousPointer = getNodeAt(newPosition - 1);

				//Inserting new node after previousPointer's node
				newNodePointer->setNext(previousPointer->getNext());
				previousPointer->setNext(newNodePointer);
			}

			//Increment count of entries
			headNode.setItemCount(headNode.getItemCount() + 1);

			//Setting tail pointer
			headNode.setLast(getNodeAt(headNode.getItemCount()));
		}

		return ableToInsert;
	}

	//Inserts a new entry at the beginning
	//@param	newEntry	new entry to be added
	//@return	true if entry successfully added
	bool insertFirst(const T& newEntry)
	{
		return insert(1, newEntry);
	}

	//Inserts a new entry at the end
	//@param	newEntry	new entry to be added
	//@return	true if entry successfully added
	bool insertLast(const T& newEntry)
	{
		return insert(headNode.getItemCount() + 1, newEntry);
	}

	//Removes an entry
	//@param	position	position of entry to be deleted
	//@return	true if entry successfully deleted
	bool remove(int position)
	{
		//Temporary pointer for deallocation of allocated memory for removed nodes
		Node<T>* currentPointer = nullptr;

		//Variable to check if position to remove is within bounds
		bool ableToRemove = (position >= 1) && (position <= headNode.getItemCount());

		if (ableToRemove)
		{
			//Removing node at beginning of chain
			if (position == 1)
			{
				//pointer to node to be removed must be saved in some temporary pointer in order to release memory allocated for removed node
				currentPointer = headNode.getNext();
				headNode.setNext(getNodeAt(2));
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
			headNode.setItemCount(headNode.getItemCount() - 1);

			//setting tail pointer
			headNode.setLast(getNodeAt(headNode.getItemCount()));
		}

		return ableToRemove;
	}

	//Removes an entry at the beginning
	//@return	true if entry successfully deleted
	bool removeFirst()
	{
		return remove(1);
	}

	//Removes an entry at the end
	//@return	true if entry successfully deleted
	bool removeLast()
	{
		return remove(headNode.getItemCount());
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
	//@param	position	position in list to get entry from
	//@return				a "T" (templatized) data item
	//@throw	outOfBounds	thrown if position is out of bounds or list is empty
	T getEntry(int position)
	{
		//Variable to check if position of entry to get is within bounds
		bool ableToGet = (position >= 1) && (position <= headNode.getItemCount());

		if (ableToGet)
		{
			Node<T>* entryNodePointer = getNodeAt(position);
			return entryNodePointer->getItem();
		}
		else
		{
			string outOfBounds = "getEntry() called with invalid position or empty list.\n";
			throw outOfBounds;
		}
	}

	//Sets an entry
	//@param	position	position in list to set entry
	//@param	newEntry	entry to add
	//@throw	outOfBounds	thrown if position is out of bounds or list is empty
	void setEntry(int position, const T& newEntry)
	{
		//Variable to check if position of entry to set is within bounds
		bool ableToSet = (position >= 1) && (position <= headNode.getItemCount());

		if (ableToSet)
		{
			Node<T>* entryNodePointer = getNodeAt(position);
			entryNodePointer->setItem(newEntry);
		}
		else
		{
			string outOfBounds = "setEntry() called with invalid position or empty list.\n";
			throw outOfBounds;
		}
	}

};

#endif