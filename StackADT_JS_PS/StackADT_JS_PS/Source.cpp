/*
Jaydeep Singh
Patrick Silvestre
Goel
CIS 22C Fall 16
Lab 2 - Stack ADT
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include "Node.h"
#include "HeadNode.h"
#include "Stack.h"
#include "SinglyLinkedList.h"

using namespace std;

void demoNodeAndHeadNode();
void demoSinglyLinkedList();
void demoStack();

int main()
{
	//Testing
	cout << "Internal Testing Only - Not for Release\n\n";
	//demoNodeAndHeadNode();
	//demoSinglyLinkedList();
	demoStack();
	
	cout << endl << "Press enter to exit.";
	cin.get();
	system("CLS");

	return 0;
}

void demoNodeAndHeadNode()
{
	//Demo of Node class
	Node<string> *nodePtr;
	nodePtr = new Node<string>("test");
	cout << "nodePtr getItem() " << nodePtr->getItem() << endl;
	cout << "nodePtr getNext() " << nodePtr->getNext() << endl;
	cout << "address of nodePtr " << nodePtr << endl << endl;

	//Demo of HeadNode class
	HeadNode<string> *headNodePtr;
	headNodePtr = new HeadNode<string>(1, nodePtr, nullptr);
	cout << "headNodePtr getItemCount() (item count) " << headNodePtr->getItemCount() << endl;
	cout << "headNodePtr getNext() (pointer to head) " << headNodePtr->getNext() << endl;
	cout << "headNodePtr getLast() (pointer to tail) " << headNodePtr->getLast() << endl << endl;

	delete nodePtr;
	nodePtr = nullptr;

	delete headNodePtr;
	headNodePtr = nullptr;
}

void demoSinglyLinkedList()
{
	//Demo of SinglyLinkedList class
	SinglyLinkedList<string> *listPtr;
	//Demo of default constructor
	listPtr = new SinglyLinkedList<string>();
	//Demo of isEmpty()
	cout << "listPtr isEmpty() " << listPtr->isEmpty() << endl;
	//Demo of getLength()
	cout << "listPtr getLength() " << listPtr->getLength() << endl;

	//Demo of insert()
	cout << "Adding the string \"test1\" at position 1 to listPtr" << endl;
	listPtr->insert(1, "test1");
	cout << "listPtr isEmpty() " << listPtr->isEmpty() << endl;
	cout << "listPtr getLength() " << listPtr->getLength() << endl;
	//Demo of getEntry()
	cout << "listPtr getEntry(1) " << listPtr->getEntry(1) << endl;

	cout << "Adding the string \"test2\" at position 2 to listPtr" << endl;
	listPtr->insert(2, "test2");
	cout << "listPtr isEmpty() " << listPtr->isEmpty() << endl;
	cout << "listPtr getLength() " << listPtr->getLength() << endl;
	cout << "listPtr getEntry(2) " << listPtr->getEntry(2) << endl;

	cout << "Adding the string \"test3\" at position 3 to listPtr" << endl;
	listPtr->insert(3, "test3");
	cout << "listPtr isEmpty() " << listPtr->isEmpty() << endl;
	cout << "listPtr getLength() " << listPtr->getLength() << endl;
	cout << "listPtr getEntry(3) " << listPtr->getEntry(3) << endl << endl;

	//Demo of copy constructor
	cout << "Creating listPtr2 and copying contents from listPtr" << endl;
	SinglyLinkedList<string> *listPtr2;
	listPtr2 = new SinglyLinkedList<string>(*listPtr);
	cout << "listPtr2 isEmpty() " << listPtr2->isEmpty() << endl;
	cout << "listPtr2 getLength() " << listPtr2->getLength() << endl;
	cout << "listPtr2 getEntry(1) " << listPtr2->getEntry(1) << endl;
	cout << "listPtr2 getEntry(2) " << listPtr2->getEntry(2) << endl;
	cout << "listPtr2 getEntry(3) " << listPtr2->getEntry(3) << endl << endl;
	
	//demo of getEntry() exception handling
	cout << "Exception Handling Test\nTrying to access listPtr2 getEntry(4)\n";
	try
	{
		cout << "listPtr2 getEntry(4) " << listPtr2->getEntry(4) << endl; 
	}
	catch (string outOfBounds)
	{
		cout << outOfBounds << endl;
	}

	//demo of setEntry() exception handling
	cout << "Exception Handling Test\nTrying to access listPtr2 setEntry(4) and initializing with the entry \"test4\"\n";
	cout << "listPtr2 setEntry(4, \"test4\") \n";
	try
	{
		listPtr2->setEntry(4, "test4");
	}
	catch (string outOfBounds)
	{
		cout << outOfBounds << endl;
	}

	////Demo of setEntry()
	cout << "Changing first item in listPtr to \"newtest1\"" << endl;
	listPtr->setEntry(1, "newtest1");
	cout << "listPtr getEntry(1) " << listPtr->getEntry(1) << endl << endl;

	//Demo of remove()
	cout << "Removing last entry in listPtr2" << endl;
	listPtr2->remove(3);	//demo of tail pointer behavior, track through watch
	cout << "listPtr2 isEmpty() " << listPtr2->isEmpty() << endl;
	cout << "listPtr2 getLength() " << listPtr2->getLength() << endl;
	cout << "listPtr2 getEntry(1) " << listPtr2->getEntry(1) << endl;
	cout << "listPtr2 getEntry(2) " << listPtr2->getEntry(2) << endl << endl;

	//Demo of insertFirst() and insertLast();
	cout << "Adding an entry \"test0\" at the beginning of listPtr2 using insertFirst() and an entry \"test3\" at the end using insertLast()" << endl;
	listPtr2->insertFirst("test0");
	listPtr2->insertLast("test3");
	cout << "listPtr2 isEmpty() " << listPtr2->isEmpty() << endl;
	cout << "listPtr2 getLength() " << listPtr2->getLength() << endl;
	cout << "listPtr2 getEntry(1) " << listPtr2->getEntry(1) << endl;
	cout << "listPtr2 getEntry(2) " << listPtr2->getEntry(2) << endl;
	cout << "listPtr2 getEntry(3) " << listPtr2->getEntry(3) << endl;
	cout << "listPtr2 getEntry(4) " << listPtr2->getEntry(4) << endl << endl;

	//Demo of removeFirst() and removeLast()
	cout << "Removing an entry at the beginning and end of list Ptr2 using removeFirst() and removeLast()" << endl;
	listPtr2->removeFirst();
	listPtr2->removeLast();
	cout << "listPtr2 isEmpty() " << listPtr2->isEmpty() << endl;
	cout << "listPtr2 getLength() " << listPtr2->getLength() << endl;
	cout << "listPtr2 getEntry(1) " << listPtr2->getEntry(1) << endl;
	cout << "listPtr2 getEntry(2) " << listPtr2->getEntry(2) << endl << endl;

	//Demo of clear()
	cout << "Clearing listPtr" << endl;
	listPtr->clear();
	cout << "listPtr isEmpty() " << listPtr->isEmpty() << endl;
	cout << "listPtr getLength() " << listPtr->getLength() << endl;

	delete listPtr, listPtr2;
	listPtr = nullptr;
	listPtr2 = nullptr;
}

void demoStack()
{
	//Demo of Stack Class
	Stack<string> *stackStringPointer;

	stackStringPointer = new Stack<string>();
	

	//Demo Behaviors
	//	Demo isEmpty
	cout << "stackPointer isEmpty() [1 indicates true. 0 false] " << stackStringPointer->isEmpty() << endl;
	//	Demo push
	cout << "will now demo push" << endl;
	stackStringPointer->push("a");
	stackStringPointer->push("b");
	stackStringPointer->push("c");
	stackStringPointer->push("d");
	cout << "printing stack" << endl;
	stackStringPointer->printStack();
	//	Demo pop
	cout << "will now demo pop" << endl;
	stackStringPointer->pop();
	stackStringPointer->pop();
	//	Demo printFirst
	cout << "will now demo print first" << endl;
	stackStringPointer->printFirst();
	stackStringPointer->push("100");
	//	Demo printStack
	cout << "will now demo print stack again" << endl;
	stackStringPointer->printStack();
	//	Demo getCount
	cout << "current count" << stackStringPointer->getCount() << endl;
	//	Demo getFirst
	cout << "get first" << stackStringPointer->getFirst() << endl;
	//	Demo getLast
	cout << "get last" << stackStringPointer->getLast() << endl;

	delete stackStringPointer;
	stackStringPointer = nullptr;
	cout << "ta da";
}
