#ifndef NODE_H
#define NODE_H
#include "rating.h"
#include <iostream>

using std::cout;

class node {
private:
  Rating data;
  node *next;
public:
  node(const Rating &r);
  const Rating& getData() const;
  Rating& getData();
  void set_next(node*);
  node *get_next();
  ~node();
   
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

node* node::get_next(){
  return next;
}

 node::~node(){
   cout<<"delete "<<endl;
}
#endif