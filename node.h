#ifndef NODE_H
#define NODE_H
#include "rating.h"
#include <iostream>
using namespace std;

class node {
private:
  Rating data;
  int studentID; 
  node *next;
public:
  node(const Rating &r);
  //node(int id); // constructor for queue (stores student ID only)
   Rating& getData() { return data; }
   const Rating& getData() const { return data; }
  void set_next(node*);
  node *get_next();
  ~node();
   
  int getStudentID() const { return studentID; }
  void setStudentID(int id) { studentID = id; }
 node(int studentID); 
};

node::node(const Rating &r){
  data = r;
  next = NULL;
}

 node::node(int studentID) { 
        this->studentID = studentID;
        next = nullptr; 
    }

void node::set_next(node *n){
  next = n;
}

node* node::get_next(){
  return next;
}

 node::~node(){
   cout<<"delete "<<endl;
}
                
#endif