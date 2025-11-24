#include <iostream>
using namespace std;
#include "ll.h"
#include "node.h"
#include "rating.h"
#include "ll.cpp"


int main(int argc, char **argv) {
    ll list;
    //loadFromFile(list); // not done
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
        cin >> choice;

        switch(choice) {
            case 1: list.addRating(); break;
            
            /*
            case 2: list.displayAll(); break;
            case 3: {
                string name; cin >> name;
                list.searchByTeacher(name);
            } break;
            case 4: {
                string name; cin >> name;
                list.searchByClass(name);
            } break;
            case 5: {
                int id; cin >> id;
                list.updateByID(id);
            } break;
            case 6: {
                int id; cin >> id;
                list.deleteByID(id);
            } break;
            case 7:
                //saveToFile(list);
                cout << "Goodbye!"<<endl;
                return 0;
                */
        }
                
    } while (true);
}
