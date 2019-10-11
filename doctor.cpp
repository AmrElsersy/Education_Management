#include "doctor.h"


Doctor & Doctor:: operator = (const Doctor& copy)
    {
        UserName = copy.UserName;
        Email = copy.Email;
        Password = copy.Password;
        ID = copy.ID;
        return *this;
    }
Doctor :: Doctor (const Doctor& Copy)
    {
        *this = Copy;
    }
Doctor :: Doctor()
    {

    }


void Doctor :: Sign_Up()
    {
        // Get the Data from the User
        cout << "Name:"; cin>> UserName;

        while (true)
        {
            cout << "Email:"; cin >> Email;
            if (Email.length() > 10)
            {
                string temp = Email.substr(Email.length() - 10);
                if (temp == "@yahoo.com")
                    break;
            }
        }

        cout << "Password:"; cin >> Password;
        cout << "ID:"; cin >> ID;
        return;
    }
void Doctor:: Sign_in()
    {
        cout << "ID:"; cin >> ID;
        cout << "Password:"; cin >> Password;
    }
void Doctor:: My_Messeges()
    {
        cout << inbox;
    }

ostream& operator << (ostream& COUT, Doctor printed)
{
    COUT << printed.UserName ;
    return COUT;
}
istream& operator >> (istream& CIN, Doctor& Get_Doctor)
{
    Get_Doctor.Sign_Up();
    return CIN;
}
