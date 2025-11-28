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

void ll::addRating() {
    Rating r;

    r.setID(nextID++);

    string input;
    while (true) {
        cout << "Enter class name: ";
        cin >> input;
        if (!input.empty()) {
            r.setClassName(input);
            break;
        }
        cout << "Class name cannot be empty. Please try again." << endl;
    }
    
    while (true) {
        cout << "Enter teacher name: ";
        cin >> input;
        if (!input.empty()) {
            r.setTeacherName(input);
            break;
        }
        cout << "Teacher name cannot be empty. Please try again." << endl;
    }

    while (true) {
        cout << "Enter score (1-5): ";
        int s;
        cin >> s;
        if (s >= 1 && s <= 5) {
            r.setScore(s);
            break;
        }
        cout << "Invalid score. Please enter a score between 1 and 5." << endl;
    }

    cout << "Enter comment: ";
    cin.ignore();
    getline(cin, input);
    r.setComment(input);

    while (true) {
        cout << "Enter student ID: ";
        int sid;
        cin >> sid;
        
        while (cin.fail()) {
          cin.clear();  // reset fail state
          cin.ignore(1000, '\n');  // remove invalid input
          cout << "Invalid input! Please enter an integer: ";
          cin >> sid;
        }
        r.setStudentID(sid);
        break;
        
    }

    // Create node
    node *newNode = new node(r);

    // Insert into list
    if (head == nullptr) {
        head = newNode;
    } else {
        node *temp = head;
        while (temp->get_next() != nullptr)
            temp = temp->get_next();
        temp->set_next(newNode);
    }

    cout << "Rating added successfully." << endl;
    r.printRating();
}


void ll::displayAll(){
  cout<< "Displaying all ratings:"<<endl;
  node* current = head;
  string input;
  while(current != nullptr){
    Rating r = current->getData();
    r.printRating();
    current = current->get_next();
  }
  if (head == nullptr){
    cout<<"No ratings to display."<<endl;
  }
  cout<<"Press enter to continue..."<<endl;
  cin.ignore(); 
  cin.get();
}



#endif