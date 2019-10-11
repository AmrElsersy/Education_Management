#include "course.h"

bool Course::  operator == (Course Check_Course)
    {
        if (Name == Check_Course.Name )
        {
            return true;
        }
        return false;
    }
Course& Course::  operator = (const Course& copy)
    {
        Name = copy.Name;
        Doctor_OF_Course = copy.Doctor_OF_Course;
        return *this;
    }
Course:: Course(const Course& Copy)
    {
        *this = Copy;
    }
Course:: Course()
    {
        Doctor_OF_Course = NULL;
    }
//ostream& operator << (ostream& COUT, Doctor printed);

ostream& operator << (ostream& COUT, Course printed)
{
    // The name of the Doctor not the pointer
    COUT << printed.Name ;
    COUT << " Dr:" ;
    COUT << * (printed.Doctor_OF_Course) ;
    return COUT;
}
istream& operator >> (istream& CIN, Course& Get_Course)
{
    return CIN;
}
