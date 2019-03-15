/*
 * Event.cpp
 *
 * Description: Event class.  Objects of this class will have a type, time, and length.
 * Class Invariant: 
 *
 * Author:   Scott Hetland, Stanley Kwok
 * Modified: February 2019
 *
 */

#include <iostream>
#include <string>
#include "Event.h"

// Default Constructor
// Description: Creates a default event.
// Postcondition: An event with type "A", 0 time, and 0 duration is created.
Event::Event() : type("A"), time(0), length(0) {}

// Parameterized Constructor
// Description: Creates an event with type, time, and length from input.
// Postcondition: An event is created with type, time, and length from input parameters.
Event::Event(string aType, int aTime, int aLength) {
    type = aType;
    time = aTime;
    length = aLength;
} 

// Getters and setters
// Description: Returns the event type.
string Event::getType() const {
    return type;
}

// Description: Returns the event time.
int Event::getTime() const {
    return this->time;
}

// Description: Returns the event length.
int Event::getLength() const {
    return length;
}

// Description: Sets the event type.
void Event::setType(const string aType) {
    type = aType;
}

// Description: Sets the event time.
void Event::setTime(const int aTime) {
    time = aTime;
}

// Description: Sets the event length.
void Event::setLength(const int aLength) {
    length = aLength;
}

// Overloaded Operators
// Description: Prints the content of "this".
ostream & operator<<(ostream & os, const Event & e) {
    os << e.getType() << ", " << e.getTime() << ", " << e.getLength() << endl;
	return os;
} // end of operator<<

// Description: Compares the time of both events and returns a boolean value
bool Event::operator<(const Event & rhs){
    if (getTime() == rhs.getTime()){
        return getType() < rhs.getType();
    }
    return getTime() < rhs.getTime();

} // end of operator<

// end of Event.cpp