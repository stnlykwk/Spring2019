/*
 * Queue.h
 *
 * Description: Queue data collection ADT
 * Class Invariant: 
 *
 * Author:   Scott Hetland, Stanley Kwok
 * Modified: February 2019
 *
 */


#pragma once
#include "Node.h"
#include "EmptyDataCollectionException.h"
#include <iostream>
#include <ostream>

using namespace std;

template <class T>
class Queue {
    private:

        Node<T> *head, *tail;
        unsigned elementCount;

    public:
    
        // Desc:  Constructor
        Queue();

        // Desc: Desct
        ~Queue();

        // Description: Inserts newElement at the "back" of this Queue 
        //              (not necessarily the "back" of its data structure) and 
        //              returns "true" if successful, otherwise "false".
        // Time Efficiency: O(1)
        bool enqueue(const T& newElement);

        // Description: Returns the number of elements in the Queue.
        // Time Efficiency: O(1)
        int getElementCount() const;

        // Description: Removes the element at the "front" of this Queue 
        //              (not necessarily the "front" of its data structure) and  
        //              returns "true" if successful, otherwise "false".
        // Precondition: This Queue is not empty.
        // Time Efficiency: O(1)
        bool dequeue();

        // Description: Returns the element located at the "front" of this Queue.
        // Precondition: This Queue is not empty.
        // Postcondition: This Queue is unchanged.
        // Exceptions: Throws EmptyDataCollectionException if this Queue is empty.
        // Time Efficiency: O(1)
        T peek() const;


        // Description: Returns "true" is this Queue is empty, otherwise "false".
        // Time Efficiency: O(1)
        bool isEmpty() const;
};

// Desc:  Constructor
    template <class T>
    Queue<T>::Queue(){
        elementCount = 0;
        head = NULL;
        tail = NULL;        
    }

// Desc: Desct
    template <class T>
    Queue<T>::~Queue(){
        int i;
        for(i=0; i<getElementCount(); i++) {
            dequeue();
        }
    }


// Description: Inserts newElement at the "back" of this Queue 
//              (not necessarily the "back" of its data structure) and 
//              returns "true" if successful, otherwise "false".
// Time Efficiency: O(1)
// Precondition: Queue exists
// Postcondition: newElement is at the "back" of this Queue
    template <class T>
    bool Queue<T>::enqueue(const T& newElement){
        Node<T> *node = new Node<T>(newElement); 
        if(node == NULL) { return false; };

        if(isEmpty()) {
            head = node;
            tail = node;
        }
        else {
            tail->next = node;
            tail = tail->next;
        }
        elementCount++;
        return true;
    }


// Description: Returns the number of elements in the Queue.
// Time Efficiency: O(1)
    template <class T>
    int Queue<T>::getElementCount() const {
        return elementCount;
    }

// Description: Removes the element at the "front" of this Queue 
//              (not necessarily the "front" of its data structure) and  
//              returns "true" if successful, otherwise "false".
// Precondition: This Queue is not empty.
// Time Efficiency: O(1)
    template <class T>
    bool Queue<T>::dequeue() {
        Node<T> *tmp = head;
        if(tmp == NULL || isEmpty()) { return false; };

        if(getElementCount() == 1) {
            head = NULL;
            tail = NULL;
        }
        else {
            head = head->next;
        }
        delete tmp;
        elementCount--;
        return true;
    }

// Description: Returns the element located at the "front" of this Queue.
// Precondition: This Queue is not empty.
// Postcondition: This Queue is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Queue is empty.
// Time Efficiency: O(1)
    template <class T>
    T Queue<T>::peek() const {
        if (isEmpty()){
            throw EmptyDataCollectionException("Queue is empty");
        } else {
            return head->data;
        }
    }

// Description: Returns "true" is this Queue is empty, otherwise "false".
// Time Efficiency: O(1)
    template <class T>
    bool Queue<T>::isEmpty() const {
        return (elementCount == 0);
    } // isempty