
#include <iomanip>
class Node {
private:
  Rating data;
  Node *nextPtr;
 // *nextPtr is next; 
 // Rating_data holds the rating information

public:
 



};
/*
typedef Node *NodePtr; // synonym for Node*

Node::Node(int x) {
  value = x;
  nextPtr = NULL;
  
}

Node::~Node() { cout << value << " deleted" << endl; }

NodePtr Node::get_next() { return nextPtr; }

int Node::get_data() { return value; }

          previousPtr->set_next(newPtr);
         newPtr->set_next(currentPtr);

void Node::set_next(NodePtr t) {
       this->nextPtr = t; 
   or use set next to set previous too
      
}

void Node::print(){
  cout << setw(3) << value;
}
*/