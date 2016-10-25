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
#include "SinglyLinkedList.h"

using namespace std;

int main()
{
	//Testing
	cout << "Internal Testing Only - Not for Release\n\n";
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

	cout << endl << "Press enter to exit.";
	cin.get();
	system("CLS");

	delete listPtr, listPtr2;
	listPtr = nullptr;
	listPtr2 = nullptr;

	return 0;
}