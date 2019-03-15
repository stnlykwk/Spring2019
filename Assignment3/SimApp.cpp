/*
 * SimApp.cpp
 *
 * Description: Banking Simulation Application
 * Class Invariant: 
 *
 * Author:   Scott Hetland, Stanley Kwok
 * Modified: February 2019
 *
 */

#include "Event.h"
#include "PriorityQueue.h"
#include "Queue.h"

#include <string>
#include <iostream>
#include <iomanip>
using namespace std;


// Description: Processes an arrival event
// Precondition: arrivalEvent, bankLine, and eventPriorityQueue exist.
// Postcondition: Arrival event is processed.
void processArrival(Event& arrivalEvent, PriorityQueue<Event>& eventPriorityQueue, Queue<Event>& bankLine, int & currentTime, bool & tellerAvailable) {
    cout << "Processing an arrival event at time:" << setw(6) << right << currentTime << endl;

    // Remove event from the event queue
    eventPriorityQueue.dequeue();

    if(bankLine.isEmpty() && tellerAvailable) {
        int departureTime = currentTime + arrivalEvent.getLength();
        Event departureEvent = Event("D", departureTime, 0);
        eventPriorityQueue.enqueue(departureEvent);
        tellerAvailable = false;
    }
    else {
        bankLine.enqueue(arrivalEvent);
    }
}


// Description: Processes a departure event
// Precondition: departureEvent, bankLine, and eventPriorityQueue exist.
// Postcondition: Departure event is processed.
void processDeparture(Event& departureEvent, PriorityQueue<Event>& eventPriorityQueue, Queue<Event>& bankLine, int & totalWaitTime, int & currentTime, bool & tellerAvailable) {     
    cout << "Processing a departure event at time:" << setw(5) << right << currentTime << endl;

    // Remove event from the event queue
    eventPriorityQueue.dequeue();

    if(!bankLine.isEmpty()) {
        try {
            Event customer = bankLine.peek();
            totalWaitTime = totalWaitTime + currentTime - customer.getTime();
            bankLine.dequeue();
            int departureTime = currentTime + customer.getLength();
            Event departureEvent = Event("D", departureTime, 0);
            eventPriorityQueue.enqueue(departureEvent);
        } catch (EmptyDataCollectionException& e){
            cout << e.what() << endl;
        }
    }
    else {
        tellerAvailable = true;
    }
}


int main (int argc, char* argv[]) {

    int numberOfPeopleProcessed = 0;
    int totalWaitTime = 0;  // or should we declare this as a global var?
    bool tellerAvailable = true;
    int currentTime = 0;

    cout << "Simulation Begins" << endl;

    Queue<Event> bankLine = Queue<Event>();
    PriorityQueue<Event> eventPriorityQueue = PriorityQueue<Event>();

    // Test EmptyDataCollectionException
    // Event test = bankLine.peek();

    // Create and add arrival events to event Queue
    while(cin.good()) {
        int tmpTime;
        int tmpLength;

        cin >> tmpTime;
        cin >> tmpLength;

        // Throw error if input file is empty
        if (tmpTime == 0 && tmpLength == 0)
            throw EmptyDataCollectionException("Empty input file.");

        Event tmpEvent = Event("A", tmpTime, tmpLength);

        // Add event to eventQueue
        eventPriorityQueue.enqueue(tmpEvent);
    }
    numberOfPeopleProcessed = eventPriorityQueue.getElementCount();

    // Event Loop
    while(!eventPriorityQueue.isEmpty()) {
        Event newEvent = eventPriorityQueue.peek();

        // Get current time
        currentTime = newEvent.getTime();

        if(newEvent.getType() == "A") {
            processArrival(newEvent, eventPriorityQueue, bankLine, currentTime, tellerAvailable);
        }
        else {
            processDeparture(newEvent, eventPriorityQueue, bankLine, totalWaitTime, currentTime, tellerAvailable);
        }
    }

    cout << "Simulation Ends" << endl << endl;
    cout << "Final Statistics:" << endl << endl;
    cout << "	" << "Total number of people processed: " << numberOfPeopleProcessed << endl;
    cout << "	" << "Average amount of time spent waiting: " << (float)totalWaitTime / (float)numberOfPeopleProcessed << endl;
    return 0;
}