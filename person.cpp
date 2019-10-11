#include "person.h"

Person::Person()
{

}

bool Person ::operator == (Person& Check_Person)
{
                if (ID == Check_Person.ID && Password == Check_Person.Password)
                {
                        return true;
                }
                return false;
}
