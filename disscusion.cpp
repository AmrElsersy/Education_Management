#include "disscusion.h"
using namespace std;

Disscusion& Disscusion :: operator = (Disscusion equaled)
    {
        Post = equaled.Post;
        return *this;
    }

ostream& operator << (ostream& COUT, Disscusion printed)
{
    COUT << printed.Post;
    return COUT;
}
