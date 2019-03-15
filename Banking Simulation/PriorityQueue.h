/*
 * PriorityQueue.h
 *
 * Description: Priority Queue
 * Class Invariant: The elements stored in this Priority Queue are always sorted.
 *
 * Author: Inspired by Frank M. Carrano and Tim Henry (textbook).
 * Modified: February 2019
 *
 */

 /* None of the current content of this file can be modified. */

#pragma once

#include <iostream>
#include "EmptyDataCollectionException.h"

using namespace std;

template <class T>  // We can use T, ElementType or other names as a placeholder
class PriorityQueue {

private:

   static const int MAX_ELEMENTS = 100;
   T elements[MAX_ELEMENTS];
   int elementCount;
   int capacity;

/* You can add private methods to this class */

public:

   // Default Constructor
   PriorityQueue();

   // Description: Returns the number of elements in the Priority Queue.
   // Time Efficiency: O(1)
   int getElementCount() const;

   // Description: Returns "true" is this Priority Queue is empty, otherwise "false".
   // Time Efficiency: O(1)
   bool isEmpty() const;

   // Description: Inserts newElement in sort order.
   //              It returns "true" if successful, otherwise "false".
   // Precondition: This Priority Queue is sorted.
   // Postcondition: Once newElement is inserted, this Priority Queue remains sorted.
   // Time Efficiency: O(n)
   bool enqueue(const T& newElement);

   // Description: Removes the element with the "highest" priority.
   //              It returns "true" if successful, otherwise "false".
   // Precondition: This Priority Queue is not empty.
   // Time Efficiency: O(1)
   bool dequeue();

   // Description: Returns the element with the "highest" priority.
   // Precondition: This Priority Queue is not empty.
   // Postcondition: This Priority Queue is unchanged.
   // Exceptions: Throws EmptyDataCollectionException if this Priority Queue is empty.
   // Time Efficiency: O(1)
   T peek() const;

   // Description: Prints the content of the priority queue
   // Time Efficiency: O(1)
   void printPriorityQueue() const;
   
}; // end PriorityQueue

// Default Constructor
// Description:  Creates a PriorityQueue with default values.
   template <class T>
   PriorityQueue<T>::PriorityQueue() : elementCount(0), capacity(MAX_ELEMENTS) {}

// Description: Returns the number of elements in the Priority Queue.
// Time Efficiency: O(1)
   template <class T>
   int PriorityQueue<T>::getElementCount() const {
      return elementCount;
   }

// Description: Returns "true" is this Priority Queue is empty, otherwise "false".
// Time Efficiency: O(1)
   template <class T>
   bool PriorityQueue<T>::isEmpty() const {
      return (getElementCount() == 0);
   }

// Description: Inserts newElement in sort order.
//              It returns "true" if successful, otherwise "false".
// Precondition: This Priority Queue is sorted.
// Postcondition: Once newElement is inserted, this Priority Queue remains sorted.
// Time Efficiency: O(n)
   template <class T>
   bool PriorityQueue<T>::enqueue(const T& newElement) 
   {
      int numberOfElements = getElementCount();

      if(numberOfElements < capacity) {
         int i, j;
         for(i=0; i<numberOfElements; i++) {
            if(elements[i] < newElement) {
               for(j=numberOfElements; j>i; j--) {
                  elements[j] = elements[j-1];
               }
               elements[i] = newElement;
               elementCount++;
               return true;
         }
      }
      elements[elementCount] = newElement;
      elementCount++;
      return true;
   }
   return false;
   }

// Description: Removes the element with the "highest" priority.
//              It returns "true" if successful, otherwise "false".
// Precondition: This Priority Queue is not empty.
// Time Efficiency: O(1)
   template <class T>
   bool PriorityQueue<T>::dequeue() {
      if(!isEmpty()) {
         elementCount--;
         return true;
      }
      return false;
   }

// Description: Returns the element with the "highest" priority.
// Precondition: This Priority Queue is not empty.
// Postcondition: This Priority Queue is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Priority Queue is empty.
// Time Efficiency: O(1)
   template <class T>
   T PriorityQueue<T>::peek() const {
      if (isEmpty()){
            throw EmptyDataCollectionException("Priority Queue is empty");
        } else {
            return elements[getElementCount() - 1];
        }
   }

// For Testing Purposes
// Description: Prints the content of "this".
   template <class T>
   void PriorityQueue<T>::printPriorityQueue() const {
      int i;
      for (i=0; i < getElementCount(); i++){
        cout << elements[i];
      }
   }
