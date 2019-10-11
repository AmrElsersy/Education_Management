#ifndef QUESTIONS_AND_ANSWERS_H
#define QUESTIONS_AND_ANSWERS_H


#include <iostream>
using namespace std;

class Questions_And_Answers
{
    string Question;
    string Answer;
    int Mark;

    friend class Quiz;
    friend class System_Flow;

    friend ostream& operator << (ostream& COUT, Questions_And_Answers printed);
    friend istream& operator >> (istream& CIN, Questions_And_Answers& Get_Student);
};

#endif // QUESTIONS_AND_ANSWERS_H
