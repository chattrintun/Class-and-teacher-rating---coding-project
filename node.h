#ifndef NODE_H
#define NODE_H
#include "rating.h"
#include <iostream>
using namespace std;

using std::cout;

class node {
private:
  Rating data;
  int studentID;
  node *next;
public:
  node(const Rating &r);
  const Rating& getData() const;
  Rating& getData();
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

const Rating& node::getData() const{
  return data;
}

Rating& node::getData(){
  return data;
}

void node::set_next(node *n){
  next = n;
}

node::node(int studentID) { 
        this->studentID = studentID;
        next = nullptr; 
    }


node* node::get_next(){
  return next;
}

 node::~node(){
   cout<<"delete "<<endl;
}
#endif