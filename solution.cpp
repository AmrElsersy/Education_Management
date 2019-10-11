#include "solution.h"

class Student;

bool Solution :: operator == (Solution compare)
{
    if (student == compare.student)
    {
        return true;
    }
    return false;
}

Solution :: Solution()
{
    Grade = 0;
}
