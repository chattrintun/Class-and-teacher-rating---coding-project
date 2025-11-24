#include <iostream>
#include <string>
#include "ll.h"
#include "rating.h"
#include "node.h"
using std::string;
using std::cout;
using std::cin;
using std::endl;

void ll::addRating() {
    Rating r;

    r.setID(nextID++);

    string input;

    cout << "Enter class name: ";
    cin >> input;
    r.setClassName(input);

    cout << "Enter teacher name: ";
    cin >> input;
    r.setTeacherName(input);

    int s;
    cout << "Enter score (1-5): ";
    cin >> s;
    r.setScore(s);

    cout << "Enter comment: ";
    cin.ignore();
    getline(cin, input);
    r.setComment(input);

    cout << "Enter student ID: ";
    int sid;
    cin >> sid;
    r.setStudentID(sid);

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
}

