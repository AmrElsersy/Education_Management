#ifndef PERSON_H
#define PERSON_H
#include "Linked_List.h"
class Course;

class Person
{
protected:
    string UserName;
    string Email;
    string Password;
    int ID;
    Linked_List<string> inbox;
    Linked_List<Course*> My_Courses;
    friend class System_Flow;
public:
    Person();
    bool operator == (Person& Check_Person);

};

#endif // PERSON_H
