#include "student.h"

Student& Student ::operator = (const Student& copy)
        {
                UserName = copy.UserName;
                Email = copy.Email;
                Password = copy.Password;
                ID = copy.ID;
                return *this;
        }
Student :: Student(const Student& Copy)
        {
                *this = Copy;
        }
Student ::Student()
        {

        }


void Student :: Sign_Up()
        {
                // Get the Data from the User
                cout << "Name:"; cin >> UserName ;

                while (true)
                {
                        cout << "Email:"; cin >> Email;
                        if (Email.length() > 10)
                        {
                                string temp = Email.substr(Email.length() - 10);
                                if (temp == "@yahoo.com" || temp == "@gmail.com")
                                        break;
                        }
                }

                cout << "Password:"; cin >> Password;
                cout << "ID:"; cin >> ID;
                return;
        }
void Student :: Sign_in()
        {
                cout << "ID:"; cin >> ID;
                cout << "Password:"; cin >> Password;
        }
void Student :: My_Messeges()
        {
                cout << inbox;
        }

ostream& operator << (ostream& COUT, Student printed)
{
        COUT << printed.UserName << "  " << printed.ID << endl;
        return COUT;
}
istream& operator >> (istream& CIN, Student& Get_Student)
{
        Get_Student.Sign_Up();
        return CIN;
}
