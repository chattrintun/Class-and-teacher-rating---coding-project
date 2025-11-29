#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "rating.h"
#include "node.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

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

    node* getHead() const; // needed by filemanager
  // for save file and load file
    void setHead(node* h) { head = h; }
    void setNextID(int n) { nextID = n; }

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

//                                              Display ALL Ratings in a formatted box
void ll::displayAll() {
    node* current = head;
    
    if (!current) {
        cout << "\n[!] No ratings found.\n" << endl; 
        return;
    }

    cout << "\n====== ALL RATINGS ======\n";

    while (current != nullptr) {
        Rating r = current->getData();
        
        // 1. Truncate data to fit fixed slots
        string className = r.getClassName().substr(0, 20);  
        string teacherName = r.getTeacherName().substr(0, 39); 
        string comment = r.getComment().substr(0, 42); 

        // 2. Draw the Box (Internal width must be EXACTLY 50 chars)
        
        cout << " __________________________________________________ " << endl;
        cout << "|                                                  |" << endl;
        
        // ROW 1: Class & Rating
        // "  CLASS: " (9) + Name (20) + "  RATING: " (10) + Score (1) + "/5" (2) = 42 chars used.
        // We need 8 spaces padding to reach 50.
        cout << "|  CLASS: " << left << setw(20) << className 
             << "  RATING: " << r.getScore() << "/5        |" << endl;
             
        // ROW 2: Teacher
        // "  TEACHER: " (11) + Name (39) = 50 chars used. Perfect fit.
        cout << "|  TEACHER: " << left << setw(39) << teacherName << "|" << endl;
        
        cout << "|--------------------------------------------------|" << endl;
        
        // ROW 3: Comment
        // "  "" (3) + Comment (42) + """ (1) = 46 chars used.
        // We need 4 spaces padding to reach 50.
        cout << "|  \"" << left << setw(42) << comment << "\"    |" << endl;
        
        // FOOTER
        // Underscores (40) + " ID: " (5) + ID (4) + " " (1) = 50 chars.
        cout << "|________________________________________ ID: " << right << setw(4) << r.getID() << " |" << endl;
        cout << endl;

        current = current->get_next();
    }
    cout<<"Press enter to continue..."<<endl;
    cin.ignore(); 
    cin.get();
}
//                                       average score by teacher (for statistics)( not done or used yet)
float ll::averageTeacher(string teacherName) {
    node* current = head;
    int totalScore = 0;
    int count = 0;

    while (current != nullptr) {
        if (current->getData().getTeacherName() == teacherName) {
            totalScore += current->getData().getScore();
            count++;
        }
        current = current->get_next();
    }

    if (count == 0) return 0.0f;
    return static_cast<float>(totalScore) / count;

}
//                                                   Save file and load file functions
void saveToFile(const ll &list, const string &filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    node* current = list.getHead();
    while (current != nullptr) {
        const Rating &r = current->getData();

        file << r.getID() << ","
             << r.getClassName() << ","
             << r.getTeacherName() << ","
             << r.getScore() << ","
             << r.getComment() << ","
             << r.getStudentID() << "\n";

        current = current->get_next();
    }

    file.close();
}
void loadFromFile(ll &list, const string &filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    // Step 1: clear current list
    node* current = list.getHead();
    while (current != nullptr) {
        node* nextNode = current->get_next();
        delete current;
        current = nextNode;
    }

    list.setHead(nullptr);  // reset head
    list.setNextID(1);      // will update after loading CSV

    string line;
    int maxID = 0;

    while (getline(file, line)) {
        stringstream ss(line);

        string s_id, className, teacherName, s_score, comment, s_studentID;

        getline(ss, s_id, ',');
        getline(ss, className, ',');
        getline(ss, teacherName, ',');
        getline(ss, s_score, ',');
        getline(ss, comment, ',');
        getline(ss, s_studentID, ',');

        Rating r;
        r.setID(stoi(s_id));
        r.setClassName(className);
        r.setTeacherName(teacherName);
        r.setScore(stoi(s_score));
        r.setComment(comment);
        r.setStudentID(stoi(s_studentID));

        maxID = max(maxID, stoi(s_id));

        // insert into list (head insert)
        node* newNode = new node(r);
        newNode->set_next(list.getHead());
        list.setHead(newNode);
    }

    list.setNextID(maxID + 1);
    file.close();
}

node* ll::getHead() const {
    return head;
}




//                                                                Delete and update DATA 
void ll::deleteByID(int id) {
    
    if (!head) {
        cout << "[!] List is empty." << endl;
        return;
    }

    node* current = head;
    node* prev = nullptr;
    //Find the node
    while (current != nullptr && current->getData().getID() != id) {
        prev = current;
        current = current->get_next();
    }

    //If ID not found
    if (current == nullptr) {
        cout << "[!] ID " << id << " not found." << endl;
        return;
    }

    // THE "CHOICE" STEP: Show details and ask for confirmation
    cout << "\n!!! WARNING: DELETING RATING !!!" << endl;
    cout << "---------------------------------" << endl;
    cout << "Class:   " << current->getData().getClassName() << endl;
    cout << "Teacher: " << current->getData().getTeacherName() << endl;
    cout << "Comment: " << current->getData().getComment() << endl;
    cout << "---------------------------------" << endl;
    
    char choice;
    cout << "Are you sure you want to delete this? (y/n): ";
    cin >> choice;

    if (choice == 'n' || choice == 'N') {
        cout << "Deletion cancelled. Nothing changed." << endl;
        return;
    }

    // 4. Perform the Delete (Unlink the node)
    if (prev == nullptr) {
        // Case: Deleting the first node (head)
        head = head->get_next();
    } else {
        // Case: Deleting a node in the middle or end
        prev->set_next(current->get_next());
    }

    delete current; // Free the memory
    cout << "[Success] Rating ID " << id << " has been deleted." << endl;
}


void ll::updateByID(int id) {
    
    node* current = head;
    bool found = false;

    while (current != nullptr) {
        if (current->getData().getID() == id) {
            found = true;
            
            // 1. Show the user the CURRENT rating so they know what they are changing
            cout << "\n=== FOUND RATING (" << id << ") ===" << endl;
            cout << "Class:   " << current->getData().getClassName() << endl;
            cout << "Teacher: " << current->getData().getTeacherName() << endl;
            cout << "Score:   " << current->getData().getScore() << "/5" << endl;
            cout << "Comment: " << current->getData().getComment() << endl;
            cout << "===========================" << endl;

            // 2. Ask what to change
            cout << "What do you want to update?" << endl;
            cout << "1. Score only" << endl;
            cout << "2. Comment only" << endl;
            cout << "3. Both" << endl;
            cout << "4. Cancel" << endl;
            cout << "Choice: ";
            
            int subChoice;
            cin >> subChoice;

            // 3. Handle the choice
            if (subChoice == 1 || subChoice == 3) {
                int newScore;
                cout << "Enter NEW Score (1-5): ";
                cin >> newScore;
                current->getData().setScore(newScore);
            }

            if (subChoice == 2 || subChoice == 3) {
                string newComment;
                cout << "Enter NEW Comment: ";
                cin.ignore(); // Clear buffer
                getline(cin, newComment);
                current->getData().setComment(newComment);
            }

            if (subChoice == 4) {
                cout << "Update cancelled." << endl;
                return;
            }

            cout << "[Success] Rating updated!" << endl;
            return; 
        }
        current = current->get_next();
    }

    if (!found) {
        cout << "[!] ID " << id << " not found." << endl;
    }
}

void ll::searchByTeacher(string teacherName){
    node* temp = head;
    int search = 0;
    if(head==nullptr){
        cout<<"Rating list is empty"<<endl;
        return;
    }

    
    while(temp != NULL){
        
        if(temp->getData().getTeacherName() == teacherName){
            temp->getData().printRating();
            cout<<endl;
            search = 1;
            
        }
        if(temp->get_next() != NULL){
            temp = temp->get_next();
        }
        else{
            break;
        }
        
    }
    if(search == 0){
        cout<<"ERROR Not found"<<endl;
    }

}

void ll::searchByClass(string className){
    node* temp = head;
    int search = 0;

    if(head==nullptr){
        cout<<"Rating list is empty"<<endl;
        return;
    }
    
    while(temp != NULL){
        if(temp->getData().getClassName() == className){
            temp->getData().printRating();
            cout<<endl;
            search = 1;
        }

        if(temp->get_next() != NULL){
            temp = temp->get_next();
        }
        else{
            break;
        }
        
    }
    if(search == 0){
        cout<<"ERROR Not found"<<endl;
    }

}

#endif