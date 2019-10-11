#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include "Linked_List.h"
#include <iostream>
#include "person.h"

using namespace std;

class Student :public Person
{

public:
    //Copy constructor && = Operator  to passing the class by value into functions
    Student& operator = (const Student& copy);
    Student(const Student& Copy);
    Student();
    void Sign_Up();
    void Sign_in();
    void My_Messeges();
    friend ostream& operator << (ostream& COUT, Student printed);
    friend istream& operator >> (istream& CIN, Student& Get_Student);
};

#endif // STUDENT_H
