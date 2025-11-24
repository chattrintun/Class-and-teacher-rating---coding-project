#ifndef NODE_H
#define NODE_H
#include "rating.h"

class node {
private:
  Rating data;
  node *next;
public:
  node(const Rating &r);;
  void set_next(node*);
  node *get_next();
  ~node();
   
};

node::node(const Rating &r){
  
  next=NULL;
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