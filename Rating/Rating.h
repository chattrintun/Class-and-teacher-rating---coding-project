#include "node.h"

class Rating {
private:
  int id; 
  string className;
  string teacherName;
  int score;
  string comment;
  int studentID;

public:
  LL();
  int deletes(int value);
  int isEmpty();
  void insert(int value);
  void printList();
  ~LL();
/* With doubly linked list*/
/*
 void printListR();
*/
};
