#include "Queue.h"
#include <iostream>
#include "node.h"

void Queue::enqueue(int studentID){
    node* newNode = new node(studentID);
    if (headPtr == NULL){
        headPtr = newNode;
        tailPtr = newNode;
    }
    else{
        tailPtr->set_next(newNode);
        tailPtr = newNode;
    }
      cout << " ID: " << studentID << " has been added to the enrollment queue." << endl;
    size++;
}

int Queue::dequeue() {
    if (headPtr == nullptr) {
        cout << "No student waiting to enroll." << endl;
        return -1;
    }

    node* temp = headPtr;
    int enrolledID = temp->getStudentID();

    headPtr = headPtr->get_next();

    if (headPtr == nullptr) {
        tailPtr = nullptr; 
    }

    delete temp;
    size--;

    cout << "ID: " << enrolledID << " has been enrolled." << endl;
    return enrolledID;
}

Queue::Queue(){
    headPtr = NULL;
    tailPtr = NULL;
    size = 0;
    
}

Queue::~Queue(){
    node* temp;
    while(headPtr != NULL){
        temp = headPtr;
        headPtr = headPtr->get_next();
        delete temp;
    }
    
}

int Queue::dropStudent(){
     if (!headPtr) {
        cout << "No student dropped from this class." << endl;
        return -1;
    }

    int droppedID = headPtr->getStudentID();
    node* temp = headPtr;
    headPtr = headPtr->get_next();
    if (!headPtr) tailPtr = nullptr;
    delete temp;
    size--;

    cout << "Student ID " << droppedID << " has dropped from the class." << endl;

    // Automatically enroll next student if exists
    if (headPtr) {
        int nextID = headPtr->getStudentID();
        cout << "Student ID " << nextID << " from waitlist is now enrolled." << endl;
        dequeue(); // remove from waitlist after enrollment
        return nextID;
    }

    return droppedID;
}

bool Queue::ClassisFull(){
    return size == CLASSSIZE;
}

bool Queue::isEmpty(){
    return size == 0;
}

    // returns true if the studentID was found & removed, false otherwise
bool Queue::removeStudent(int studentID) {
    if (!headPtr) return false;

    // special case: head matches
    if (headPtr->getStudentID() == studentID) {
        node* tmp = headPtr;
        headPtr = headPtr->get_next();
        if (!headPtr) tailPtr = nullptr;
        delete tmp;
        size--;
        return true;
    }

    // search for node with matching studentID
    node* prev = headPtr;
    node* curr = headPtr->get_next();
    while (curr) {
        if (curr->getStudentID() == studentID) {
            prev->set_next(curr->get_next());
            if (curr == tailPtr) tailPtr = prev;
            delete curr;
            size--;
            return true;
        }
        prev = curr;
        curr = curr->get_next();
    }

    return false;
}
   
