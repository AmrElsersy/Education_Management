#ifndef COURSE_H
#define COURSE_H

#include "Linked_List.h"
#include "disscusion.h"
#include "quiz.h"
#include "doctor.h"


class Student;
class Course
{
    string Name;
    Doctor* Doctor_OF_Course;
    Linked_List<string> Announcemnts;
    Linked_List<Disscusion> Disscusions;
    Linked_List<Quiz> Quizes;
    Linked_List<Student*> students;

    friend class System_Flow;
public:
    bool operator == (Course Check_Course);
    Course& operator = (const Course& copy);
    Course(const Course& Copy);
    Course();

    friend ostream& operator << (ostream& COUT, Course printed);
    friend istream& operator >> (istream& CIN, Course& Get_Course);
};
ostream& operator << (ostream& COUT, Course printed);
istream& operator >> (istream& CIN, Course& Get_Course);
#endif // COURSE_H
