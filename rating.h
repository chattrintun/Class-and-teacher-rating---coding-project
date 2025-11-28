#include "node.h"
#include <string>
#include <iostream>
#ifndef RATING_H
#define RATING_H

using std::string;
using std::cout;
using std::endl;

class Rating {
private:
  int id; // id of the class ex,, ecgi203
  string className;
  string teacherName;
  int score;
  string comment;
  int studentID;

public:
    void printRating();
    // set id to something
    void setID(int v) { id = v; }
    void setClassName(const string &v) { className = v; }
    void setTeacherName(const string &v) { teacherName = v; }
    void setScore(int v) { score = v; }
    void setComment(const string &v) { comment = v; }
    void setStudentID(int v) { studentID = v; }

    //get id value
    int getID() const { return id; }
    string getClassName() const { return className; }
    string getTeacherName() const { return teacherName; }
    int getScore() const { return score; }
    string getComment() const { return comment; }
    int getStudentID() const { return studentID; }
};

void Rating :: printRating() {
    cout << "ID: " << id << endl;
    cout << "Class: " << className << endl;
    cout << "Teacher: " << teacherName << endl;
    cout << "Score: (" << score << "/5)"<< endl;
    cout << "Comment: " << comment << endl;
    //cout << "Student ID: " << studentID << endl;
}

#endif