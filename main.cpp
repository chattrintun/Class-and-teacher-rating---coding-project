#include <iostream>
#include <fstream>
#define CLASSSIZE 30
using namespace std;
#include "ll.h"
#include "node.h"
#include "rating.h"
#include "ll.cpp"
#include <iomanip>
#include "map"
#include "Queue.h"
#include "Queue.cpp"



int main(int argc, char **argv) {
    ll list;
    loadFromFile(list, "ratings.csv");
    //sky +1 for effort
    //wad kao eitoo kwang ped 
    
    int choice;

    do {
        cout <<endl<< "--- CLASS & TEACHER RATING SYSTEM ---"<<endl;
        cout << "1. Add Rating"<<endl;
        cout << "2. Display All Ratings"<<endl;
        cout << "3. Search by Teacher"<<endl;
        cout << "4. Search by Class"<<endl;
        cout << "5. Update Rating"<<endl;
        cout << "6. Delete Rating"<<endl;
        cout << "7. Save & Exit"<<endl;
        cout << "8. Enroll to Class" << endl;
        cout << "9. Drop from Class" << endl;
        cin >> choice;

        switch(choice) {
            case 1: list.addRating(); break;
            
            
            case 2: list.displayAll(); break;
            
            case 3: {
                string name;
                cout<<"Name of the teacher to search: ";
                 cin >> name;
                list.searchByTeacher(name);
            } break;
            
            case 4: {
                string name; 
                cout<<"Name of the Class to search: ";
                cin >> name;
                list.searchByClass(name);
            } break;
             
            case 5: { // UPDATE
                // Show list first so user can find the ID
                cout << "\n--- LIST OF RATINGS ---" << endl;
                list.displayAll(); 
                
                int id; 
                cout << "Enter Rating ID to Update (from list above): ";
                cin >> id;
                list.updateByID(id);
            } break;

            case 6: { // DELETE
            // Show all ratings first so user can pick an ID
                cout << "\n--- SELECT RATING TO DELETE ---" << endl;
                list.displayAll();

            // Ask for ID
                int id; 
                cout << "Enter Rating ID to Delete: ";
                cin >> id;

            // Call the smart delete function
                list.deleteByID(id);
            } break;
             
            case 7: // save and exit
                saveToFile(list, "ratings.csv");
                cout << "Goodbye!"<<endl;
                return 0;
            case 8: {
    int stuID;
    cout << "Enter your student ID: ";
    cin >> stuID;
    list.enroll(stuID);
}
break; 
    case 9: {
    int stuID;
    cout << "Enter your student ID: ";
    cin >> stuID;
    list.drop(stuID);
}
break;
                
        }
                
    } while (true);
}
