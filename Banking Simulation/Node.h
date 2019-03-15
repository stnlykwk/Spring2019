/*
 * Node.h
 *
 * Description: Node of a singly linked list 
 *              in which the data is of "T" data type.
 *              Designed and implemented as a non-ADT.
 * Class Invariant: 
 *
 * Author:   Scott Hetland, Stanley Kwok
 * Modified: February 2019
 *
 */

#pragma once
#include <cstddef>
using namespace std;

template <class T>
class Node
{
public:
	T data;     // The data in the node
	Node<T>* next;   // Pointer to next node
	
	// Constructors
	// Default constructor
	// Description:  Creates a node without data and next pointer is set to NULL.
	Node();

	// Parameterized constructor
	// Description:  Creates a node and sets data from input and next pointer to NULL.
	Node(T theData);

}; // end Node

// Default constructor
// Description:  Creates a node without data and next pointer is set to NULL.
template <class T>
Node<T>::Node()
{
	next = NULL;
}

// Parameterized constructor
// Description:  Creates a node and sets data from input and next pointer to NULL.
template <class T>
Node<T>::Node(T theData)
{
	data = theData;
	next = NULL;
}