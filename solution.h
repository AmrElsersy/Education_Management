#ifndef SOLUTION_H
#define SOLUTION_H

#include "Linked_List.h"
class Student;
class Solution
{
private:
    Linked_List<string> Student_Answers;
    int Grade;
    Student* student;
    friend class Quiz;
    friend class System_Flow;

public:
    bool operator == (Solution compare);
    friend ostream& operator << (ostream& COUT, Solution printed);
    Solution();
};


#endif // SOLUTION_H
