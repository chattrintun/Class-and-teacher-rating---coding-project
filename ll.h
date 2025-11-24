#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "rating.h"
#include "node.h"
#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::cin;
using std::endl;

class ll {
private:
  node* head;
  int nextID;

public:
  ll();
  ~ll();

  void addRating(); //insert to list
  void displayAll();  // Print entire list
  void searchByTeacher(string teacherName); // Find matching nodes
  void searchByClass(string className); // Same but by class
  void updateByID(int id); // Modify data
  void deleteByID(int id); // Delete from list

  float averageTeacher(string teacherName); //Statistics
  float averageClass(string className); // Statistics

  node* getHead(); // needed by filemanager
};
ll::ll() {
    head = nullptr;
    nextID = 1;
}
ll::~ll() {
    node* current = head;
    while (current != nullptr) {
        node* nextNode = current->get_next();
        delete current;
        current = nextNode;
    }
}
#endif