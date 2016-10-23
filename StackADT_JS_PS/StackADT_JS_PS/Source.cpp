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

using namespace std;

int main()
{
	//Demo of Node class
	Node<string> *nodePtr;
	nodePtr = new Node<string>("test");
	cout << nodePtr->getItem() << endl << nodePtr->getNext();

	delete nodePtr;
	return 0;
}