#ifndef QUIZ_H
#define QUIZ_H
#include "solution.h"
#include "questions_and_answers.h"
#include "Linked_List.h"


class Quiz
{
    int Max_Grade;
    Linked_List<Questions_And_Answers> Questions;
    Linked_List<Solution> Quiz_Solutions;

    friend class System_Flow;
    friend ostream& operator << (ostream& COUT, Quiz printed);
    friend istream& operator >> (istream& CIN, Quiz& Get_Student);

public:
    void Set_Max_Grade();
    void Add_Questions(int size);
    void Add_1_Solution();
};
#endif // QUIZ_H
