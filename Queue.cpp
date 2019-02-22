/* 
 * Queue.cpp
 *
 * Description: Implementation of a Queue ADT class       
 * Class Invariant: ... in FIFO or LILO order.
 *
 * Author:
 * Date:
 */

#include <cstddef>
#include <iostream> 
#include "Queue.h"

using namespace std;

// Desc: Constructor
// Post: Queue is empty
Queue::Queue() : elementCount(0), head(NULL), tail(NULL) {
} // constructor


// Desc:  Destructor
// Post:  Queue is empty
Queue::~Queue() {
	Queue::Node * temp = head;

	for ( unsigned int i = 0; i < elementCount; i++ ) {
		head = head->next;
		delete temp;
		temp = head;
	}
	elementCount = 0;
	tail = NULL;
} // destructor

// Desc: Reverse the elements of a Queue.
//       On success, returns "true", "false" otherwise.
//       For example, if a Queue is 5 7 2 4, 
//       then the reversed Queue is 4 2 7 5.
//       A Queue of 1 element is already reversed, so nothing 
//       should be done except returning "true".
//       This method must be implemented without creating new Node objects,
//       and without changing the data in already existing Node objects.
//       Only the "next" attribute of a Node object can be changed. 
bool Queue::reverse() {

  	if (elementCount == 1)
		return true;

	int arr[elementCount] = {0};
	Node *tmp = head;
	bool reversed = false;

	for (int i = 0; i < elementCount; i++) {
		arr[i] = tmp->data;
		tmp = tmp->next;
	}

	Node *cur = head->next, *prev = head;

	while (cur->next != NULL) {
		cur = cur->next;
		prev = prev->next;
	}

	cur->next = prev;
	prev = head;
	cur = head->next;

	for (int i = 0; i < elementCount-1; i++) {
		while (cur->next->next != cur) {
			cur = cur->next;
			prev = prev->next;
		}
		cur->next = prev;
		prev = head;
		cur = head->next;
	}
	
	tmp = head;
	head = tail;
	tail = tmp;

	tmp = head;

	for (int i = 0; i < elementCount; i++) {
		if (tmp->data == arr[i]) {
			reversed = true;
		}
		else {
			reversed = false;
		}
	}

	return reversed;
	
} // reverse


// Desc: Inserts newElement at the "back" of this Queue in O(1)
//       and returns "true" if successful, otherwise "false".	
bool Queue::enqueue(int newElement) {
	Node * temp = new Node( );
	bool result = true;

	if ( temp == NULL ) result = false;
	else {
		temp->data = newElement;
		temp->next = NULL;

		// Assuming head and tail NULL
		if ( isEmpty() ) head = temp;
		else tail->next = temp;

		tail = temp;
		elementCount++;
	}
    return result;

} // enqueue

// Desc: Removes the element at the "front" of this Queue in O(1) 
//       and returns "true" if successful, otherwise "false".
// Pre: This Queue is not empty.
bool Queue::dequeue() {
	Node * temp = NULL;
	bool result = true;

	if ( isEmpty() ) result = false;
	else {
		temp = head;
		head = head->next;
		if ( head == NULL ) tail = NULL;
		delete temp;
		temp = NULL;
	    elementCount--;
	}
    return result;
} // dequeue

// Desc: Returns the element at the "front" of this Queue in O(1).
// Pre: This Queue is not empty.
// Post: This Queue is unchanged.		
int Queue::peek() const {
	int result = 0;  // For now!

	if ( !isEmpty() )
		result = head->data;
    return result;
} // peek


// Desc: Returns "true" is this Queue is empty, otherwise "false" in O(1).
// Post: This Queue is unchanged.
bool Queue::isEmpty() const {
    return elementCount == 0;
} // isempty


// Desc: Prints all the elements of the Queue in FIFO/LILO order.
//       If the Queue is empty, it prints "Empty Queue!".     
// Post: This Queue is unchanged.
void Queue::printQ() const{
	Node * temp = head;
	unsigned int i = 0;

	if ( !isEmpty() ) {
		for ( i = 0; i < elementCount; i++ ) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	else
		cout << "Empty Queue!" << endl;
}