#ifndef QUEUE_H
#define QUEUE_H
#define CLASSSIZE 30
#include <iostream>
using namespace std;

class node; // Forward declaration

class Queue {
    node* headPtr;
    node* tailPtr;
    int size;
public:
    void enqueue(int studentID);
    int dequeue();
    Queue();
    ~Queue();
    bool ClassisFull();
    bool isEmpty();
    int dropStudent();
    bool removeStudent(int studentID);
}; 

#endif