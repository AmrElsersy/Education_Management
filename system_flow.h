#ifndef SYSTEM_FLOW_H
#define SYSTEM_FLOW_H

#include "Linked_List.h"

#include "course.h"
#include "student.h"
#include "doctor.h"
#include "questions_and_answers.h"
#include "quiz.h"
#include "solution.h"
#include "disscusion.h"

#include <QString>
#include <fstream>
using namespace std;

class System_Flow
{
private:
        Linked_List<Doctor> Doctors;
        Linked_List<Student> Students;
        Linked_List<Course> Courses;
        QString dummy_path;
public:
        System_Flow(QString path);
        ~System_Flow();

        void  Get_int(int& num);
        void  Get_Started();
        void  Sign_in();
        void  Sign_up();
        bool  Check_Sign_Up_Student(Student Check);
        bool  Check_Sign_Up_Doctor(Doctor Check);
        void  Student_Home(int pos);
        void  Student_Courses(int pos);
        void  Register(int pos);
        void  Student_Course_Home(int Course_pos, int pos);
        void  Quizes(int Course_pos, int pos);
        void  Announcments(int Course_pos, int pos);
        void  Disscusions(int Course_pos, int pos);
        void  Grade_Report(int Course_pos, int pos);
        void  UnRegister(int Course_pos, int pos);
        void  Doctor_Home(int pos);
        void  Doctor_Courses(int pos);
        void  Add_Course(int pos);
        void  Doctor_Course_Home(int Course_pos, int pos);
        void  Add_Quiz(int Course_pos, int pos);
        void  Add_Anouncment(int Course_pos, int pos);
        void  Doctor_Disscusion(int Course_pos, int pos);
        void  Students_Of_Course(int Course_pos, int pos);
        void  Doctor_inbox(int pos);
        void  Student_inbox(int pos);
        void  Helpfull_FOR_inbox(string Name_Send, int Choice ,string Doctor_OR_Student , int pos);
        void  DymmyData();

};

#endif // SYSTEM_FLOW_H
