/* 
 * Stack.cpp
 *
 * Description: Implementation of an int sequence with push/pop ...
 * Class Invariant: Stack implementation in a LIFO order
 *
 * Author:  Stanley Kwok
 * Date created:  January 31, 2019
 */
 
#include <cstddef>  // For NULL
#include <ostream>
#include <iostream>
#include "Stack.h"

using namespace std;

// Desc:  Default Constructor
// Post:  New empty stack is created
Stack::Stack() { head = NULL; tail = NULL; }

// Desc:  Destructor
// Post:  Stack is destroyed and memory released.
Stack::~Stack() {}

// Desc:  Insert element x to the top of the stack.
// Post:  Element x is at the end of the list.
//        List's element count increased by one
void Stack::push(int x) {
    StackNode *newNode = new StackNode();

    newNode->data = x;
    
    if(head == NULL) {
        head = newNode;
        tail = newNode;
    } 
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

// Desc:  Remove and return element at the top of the stack.
//  Pre:  Stack is not empty.
// Post:  Element at top of stack is removed and returned.
int Stack::pop() {
    if(head == NULL || tail == NULL) {
        cout<<"head or tail is null"<<endl;
        return -1;
    }

    if(head == tail) {
        int temp = head->data;
        
        head->next = NULL;
        
        delete head;
        
        head = NULL;
        tail = NULL;
        
        return temp;
    }

    // declare local vars
    StackNode *prev = head;
    int tmp;

    // move pointer to node prior to tail
    while(prev->next != tail)
        prev = prev->next;
        
    tmp = tail->data;

    delete tail;

    tail = prev;
    tail->next = NULL;

    return tmp;
}


// Desc:  Return the topmost element of the stack.
//  Pre:  Stack is not empty.
// Post:  Element at top of stack is returned.  Stack not modified.      
int Stack::peek() const {
    if(head == NULL || tail == NULL)
        return -1;

    if(head == tail) {
        return head->data;
    } 
    else {
        return tail->data;
    }
}

// Desc:  Checks if rhte stack if empty.
// Post:  Returns true if stack is empty, false if not.
bool Stack::isEmpty() const {
    if(head == NULL || tail == NULL) {
        return true;
    } 
    else {
        return false;
    }
}