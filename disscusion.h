#ifndef DISSCUSION_H
#define DISSCUSION_H


#include "Linked_List.h"


class Disscusion
{
    string Post;
    Linked_List<string> Replay;
    friend class System_Flow;
    friend ostream& operator << (ostream& COUT, Disscusion printed);
public:
    Disscusion & operator = (Disscusion equaled);
};


#endif // DISSCUSION_H
