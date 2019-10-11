#ifndef DOCTOR_H
#define DOCTOR_H
#include "person.h"
#include "Linked_List.h"
using namespace std;


class Doctor : public Person
{
public:
    Doctor & operator = (const Doctor& copy);
    Doctor(const Doctor& Copy);
    Doctor();
    void Sign_Up();
    void Sign_in();
    void My_Messeges();

    friend ostream& operator << (ostream& COUT, Doctor printed);
    friend istream& operator >> (istream& CIN, Doctor& Get_Student);
};

#endif // DOCTOR_H
