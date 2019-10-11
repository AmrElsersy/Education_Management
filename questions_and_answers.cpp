#include "questions_and_answers.h"

ostream& operator << (ostream& COUT, Questions_And_Answers printed)
{
    COUT << printed.Question << "\t" << printed.Mark <<"Mark" << endl;
    return COUT;
}
istream& operator >> (istream& CIN, Questions_And_Answers& Get_Questions)
{
    cout << "Question:"; getline(CIN>>ws, Get_Questions.Question);
    cout << "Answer:";   getline(CIN>>ws, Get_Questions.Answer);
    cout << "Mark:";	CIN >> Get_Questions.Mark;

    return CIN;
}
