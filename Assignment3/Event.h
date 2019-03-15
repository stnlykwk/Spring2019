/*
 * Event.h
 *
 * Description: Event class.  Objects of this class will have a type, time, and length.
 * Class Invariant: 
 *
 * Author:   Scott Hetland, Stanley Kwok
 * Modified: February 2019
 *
 */

#pragma once
#include <string>
using namespace std;


class Event {
    private:
        string type;
        int time;
        int length;

    public:
        // Default Constructor
        // Description: Creates a default event.
        // Postcondition:An event with type "A", 0 time, and 0 duration is created.
        Event();

        // Parameterized Constructor
        // Description: Creates an event with type, time, and length from input.
        // Postcondition: An event is created with type, time, and length from input parameters.
        Event(string aType, int aTime, int aLength);


        // Getters and setters
        // Description: Returns the event type.
        string getType() const;

        // Description: Returns the event time.
        int getTime() const;

        // Description: Returns the event length.
        int getLength() const;

        // Description: Sets the event type.
        void setType(const string aType);

        // Description: Sets the event time.
        void setTime(const int aTime);

        // Description: Sets the event length.
        void setLength(const int aLength);

        // Overloaded Operators
        // Description: Prints the content of "this".
        friend ostream & operator<<(ostream & os, const Event & e);

        // Description: Compares the time of both events and returns a boolean value
        bool operator<(const Event & rhs);

}; // end of Event.h