#include "quiz.h"


void Quiz :: Set_Max_Grade()
    {
        for (int i = 0 , n=  Questions.Size(); i < n; i++)
        {
            Max_Grade += Questions[i].Mark;
        }
    }
void Quiz :: Add_Questions(int size)
    {
        Questions.Create_List(size);
    }
void Quiz:: Add_1_Solution()
    {
        Solution Temp;
        Quiz_Solutions.Add(Temp);
    }

ostream& operator << (ostream& COUT, Quiz printed)
{
    return COUT;
}
istream& operator >> (istream& CIN, Quiz& Get_Quiz)
{
    cin >> Get_Quiz.Questions;
    return CIN;
}
