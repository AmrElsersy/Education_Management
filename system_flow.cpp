#include "system_flow.h"

// Get_int Just helpfull funcion
void System_Flow :: Get_int(int& num)
{
    string temp;
    getline(cin >> ws, temp);
    for (int i = 0, n = temp.length(); i < n; i++)
    {
        if (!isdigit(temp[i]))
        {
            Get_int(num);
            return;
        }
    }
    num = atoi(temp.c_str());
    return;
}

void  System_Flow :: Get_Started()
{
    cout << "1-Sign in" << "\n";
    cout << "2-Sign Up" << "\n";
    cout << "3-Exit" << "\n";

    int Choice;
    Get_int(Choice);

    if (Choice == 1)
    {
        Sign_in();
    }
    else if (Choice == 2)
    {
        Sign_up();
    }
    else if (Choice == 3)
    {
        this->~System_Flow();
        exit(1);
    }

}
void  System_Flow :: Sign_in()
{
    cout << "1-Student" << "\n";
    cout << "2-Doctor" << "\n";
    cout << "3-Back" << "\n";

    int Choice;
    Get_int(Choice);

    if (Choice == 1)
    {
        Student Temp;
        Temp.Sign_in();

        int found = Students.Find(Temp);
        if (found == -1)
        {
            cout << "Your Name or Password are invalid" << endl;
            Get_Started();
        }

        Student_Home(found);

    }
    else if (Choice == 2)
    {
        Doctor Temp;
        Temp.Sign_in();

        int found = Doctors.Find(Temp);
        if (found == -1)
        {
            cout << "Your Name or Password are invalid" << endl;
            Get_Started();
        }

        Doctor_Home(found);
    }
    else if (Choice == 3)
    {
        Get_Started();
    }
    else
    {
        cout << "Enter 1 , 2 , 3 " << endl;
        Sign_in();
    }
}
void  System_Flow :: Sign_up()
{
    cout << "1-Student" << "\n";
    cout << "2-Doctor" << "\n";
    cout << "3-Back" << "\n";

    int Choice;
    Get_int(Choice);

    if (Choice == 1)
    {
        Student Temp;
        Temp.Sign_Up();

        if (Check_Sign_Up_Student(Temp))
        {
            cout << "Your ID or Email is invalid" << endl;
            Get_Started();
        }
        else
        {
            Students.Add(Temp);
            Student_Home(-1);
        }
    }
    else if (Choice == 2)
    {
        Doctor Temp;
        Temp.Sign_Up();

        if (Check_Sign_Up_Doctor(Temp))
        {
            cout << "Your ID or Email is invalid" << endl;
            Get_Started();
        }
        else
        {
            Doctors.Add(Temp);
            Doctor_Home(-1);
        }
    }
    else if (Choice == 3)
    {
        Get_Started();
    }
    else
    {
        cout << "Enter 1 , 2 , 3 " << endl;
        Sign_up();
    }
}
// Check for repeated ID or Email in Your List
bool  System_Flow :: Check_Sign_Up_Student(Student Check)
{
    for (int i = 0, n = Students.Size(); i < n; i++)
    {
        if (Students[i].ID == Check.ID || Students[i].Email == Check.Email)
        {
            return true;
        }
    }
    return false;
}
bool System_Flow ::  Check_Sign_Up_Doctor(Doctor Check)
{
    for (int i = 0, n = Doctors.Size(); i < n; i++)
    {
        if (Doctors[i].ID == Check.ID || Doctors[i].Email == Check.Email)
        {
            return true;
        }
    }
    return false;
}

// ............... Student.....................
void System_Flow ::  Student_Home(int pos)
{
    cout << endl;
    cout << "1-My Courses" << endl;
    cout << "2-Register" << endl;
    cout << "3-inbox" << endl;
    cout << "4-Sign out" << endl;

    int Choice;
    Get_int(Choice);
    if (Choice == 1)
        Student_Courses(pos);
    else if (Choice == 2)
        Register(pos);
    else if (Choice == 3)
        Student_inbox(pos);
    else if (Choice == 4)
    {
        Get_Started();
        return;
    }
    else
        Student_Home(pos);
}
void System_Flow ::  Student_Courses(int pos)
{
    int n = Students[pos].My_Courses.Size();
    // if we Don't have Courses ... Return
    if (n == 0)
    {
        Student_Home(pos);
    }
    // we Can't use (cout << Doctors[pos].My_Courses;) as it prints value and we dealing here with pointers
    // (we don't need the adress we need the course it's self)
    for (int i = 0, n = (Students[pos].My_Courses).Size(); i < n; i++)
    {
        cout << i + 1 << "-" << *(Students[pos].My_Courses[i]) << endl;
    }

    int Choice;
    while (true)
    {
        cin >> Choice;
        if (Choice <= n && Choice > 0)
            break;
    }

    // return to Home
    Student_Course_Home(Choice - 1, pos);
}
void System_Flow ::  Register(int pos)
{
    // counter for printing the count of Unregistered Courses
    // Temp pos is for storing the Un registered Courses in the Temp List
    int counter = 0;
    int Temp_pos = -1;
    // Temp is a List that will we store pointers of Unregistered Courses to Access them easily
    Linked_List<Course*> Temp;

    for (int i = 0, n = Courses.Size(); i < n; i++)
    {
        // if there is a Regestered Course (in Student Courses) .... Skip
        if ((Students[pos].My_Courses).Find(&Courses[i]) != -1)
        {
            continue;
        }
        Temp.Add(&Courses[i]);
        Temp_pos++;
        counter++;
        cout << counter << "-" << *Temp[Temp_pos];
    }
    if (Temp.Size() == 0)
    {
        Student_Home(pos);
        return;
    }

    // Choice of Course is Choosen
    // Choice - 1 as we printed a counter from 1 not 0
    int Choice = 0;
    // make Sure that user will Not enter Num > than Counter
    while (true)
    {
        cin >> Choice;
        if (Choice <= counter && Choice > 0)
            break;
    }
    // Make the Student Points at the Course
    (Students[pos].My_Courses).Add(Temp[Choice - 1]);
    // Make The Course Points at the Student
    (Temp[Choice - 1]->students).Add(&Students[pos]);
    // ........ Note that we Access the Unregistered Courses By pointers So we Couldn't use just a List of Courses .........

    Student_Home(pos);
}

// ............... Student Course......................
void  System_Flow :: Student_Course_Home(int Course_pos, int pos)
{
    cout << endl;
    cout << *(Students[pos].My_Courses[Course_pos]);
    cout << "1-Quizes" << endl;
    cout << "2-Announcments" << endl;
    cout << "3-Disscusions" << endl;
    cout << "4-Grade Report" << endl;
    cout << "5-Back" << endl;
    cout << "6-UnRegister" << endl;

    int Choice;
    Get_int(Choice);

    if (Choice == 1)
        Quizes(Course_pos, pos);
    else if (Choice == 2)
        Announcments(Course_pos, pos);
    else if (Choice == 3)
        Disscusions(Course_pos, pos);
    else if (Choice == 4)
        Grade_Report(Course_pos, pos);
    else if (Choice == 5)
        Student_Home(pos);
    else if (Choice == 6)
        UnRegister(Course_pos, pos);
    else
        Student_Course_Home(Course_pos, pos);

}
// Dangerous Function Be Carfull :D
void  System_Flow :: Quizes(int Course_pos, int pos)
{
    // print all Quizes of The Course
    int n = (Students[pos].My_Courses[Course_pos])->Quizes.Size();
    // if there is No Courses
    if (n == 0)
    {
        Student_Course_Home(Course_pos, pos);
        return;
    }

    for (int i = 1; i <= n; i++)
        cout << i << "-" << "Quiz" << i << endl;

    // Check if User Write a wrong Num
    int Choice;
    while (true)
    {
        Get_int(Choice);
        if (Choice <= n && Choice > 0)
            break;
    }
    cout << endl;
    cout << "1-Start-Quiz" << endl;
    cout << "2-Modle Answer" << endl;
    cout << "3-Grade" << endl;
    cout << "4-Back" << endl;

    int Choose;
    while (true)
    {
        Get_int(Choose);
        if (Choose <= 4 && Choose > 0)
            break;
    }

    if (Choose == 1)
    {	// ...................................Check (you can skip it )...................................
        // if he Choose Modle Answer We Check first if he Ended the Quiz
        // Adding Temp Object and Store Adress of Student in it to Search in All Quize_Solution by The Adress of The Student
        Solution temp;	temp.student = &Students[pos];
        int Check = Students[pos].My_Courses[Course_pos]->Quizes[Choice - 1].Quiz_Solutions.Find(temp);
        // if it is  found = he Submited Solution Already
        if (Check != -1)
        {
            cout << "You Submitted This Quiz Befor" << endl;
            Quizes(Course_pos, pos);
            return;
        }
        // ...............................................................................................

        // Number of solutions in one Solution = Number of Questions
        int m = (Students[pos].My_Courses[Course_pos])->Quizes[Choice - 1].Questions.Size();
        // Add Memory for one Student Solution in the Quiz
        (Students[pos].My_Courses[Course_pos])->Quizes[Choice - 1].Add_1_Solution();
        // make the Num of Solutions of Student = Num of Questions
        (Students[pos].My_Courses[Course_pos])->Quizes[Choice - 1].Quiz_Solutions[-1].Student_Answers.Create_List(m);

        for (int i = 0; i < m; i++)
        {
            // Question i ........  2 Marks
            cout << (Students[pos].My_Courses[Course_pos])->Quizes[Choice - 1].Questions[i];
            // Get the i Solution from Student
            getline(cin>>ws, (Students[pos].My_Courses[Course_pos])->Quizes[Choice - 1].Quiz_Solutions[-1].Student_Answers[i]);
            // if Solution == Model Answer
            if ((Students[pos].My_Courses[Course_pos])->Quizes[Choice - 1].Questions[i].Answer ==
                    (Students[pos].My_Courses[Course_pos])->Quizes[Choice - 1].Quiz_Solutions[-1].Student_Answers[i])
            {
                // Grade += 2 Marks
                Students[pos].My_Courses[Course_pos]->Quizes[Choice - 1].Quiz_Solutions[-1].Grade
                        += (Students[pos].My_Courses[Course_pos])->Quizes[Choice - 1].Questions[i].Mark;
            }
        }
        // Make the Solution points at it's Student
        Students[pos].My_Courses[Course_pos]->Quizes[Choice - 1].Quiz_Solutions[-1].student = &Students[pos];
    }
    else if (Choose == 2)
    {
        // if he Choose Modle Answer We Check first if he Ended the Quiz
        // Adding Temp Object and Store Adress of Student in it to Search in All Quize_Solution by The Adress of The Student
        Solution temp;	temp.student = &Students[pos];
        int Check = Students[pos].My_Courses[Course_pos]->Quizes[Choice - 1].Quiz_Solutions.Find(temp);
        // if it is not found = he did't Submit Solution Yet -> Don't Show it
        if ( Check == -1 )
        {
            cout << "You Didn't Start the Quiz Yet" << endl;
            Quizes(Course_pos, pos);
            return;
        }

        // .....................................................................................................................

        for (int i = 0, k = (Students[pos].My_Courses[Course_pos])->Quizes[Choice - 1].Questions.Size(); i < k; i++)
        {
            cout << (Students[pos].My_Courses[Course_pos])->Quizes[Choice - 1].Questions[i];
            cout << "Your Answer:" << Students[pos].My_Courses[Course_pos]->Quizes[Choice - 1].Quiz_Solutions[Check].Student_Answers[i] << endl;
            cout << "Correct:" << (Students[pos].My_Courses[Course_pos])->Quizes[Choice - 1].Questions[i].Answer << endl;
        }
        // for printing total Grade
        cout << (Students[pos].My_Courses[Course_pos])->Quizes[Choice - 1].Quiz_Solutions[Check].Grade << "/";
        cout << (Students[pos].My_Courses[Course_pos])->Quizes[Choice - 1].Max_Grade << endl;
        cout << endl;
    }
    else if (Choose == 3)
    {
        // Solution temp storing adress of the Student to Search for Adress in Solution to make Sure that he is found
        Solution temp;	temp.student = &Students[pos];
        int Check = Students[pos].My_Courses[Course_pos]->Quizes[Choice - 1].Quiz_Solutions.Find(temp);
        // if not found ... -> he didn't submit sloution
        if (Check == -1)
        {
            cout << "You Didn't Start the Quiz Yet" << endl;
            Quizes(Course_pos, pos);
            return;
        }

        cout << (Students[pos].My_Courses[Course_pos])->Quizes[Choice - 1].Quiz_Solutions[Check].Grade << "/" ;
        cout << (Students[pos].My_Courses[Course_pos])->Quizes[Choice - 1].Max_Grade << endl;
    }
    else if (Choose == 4)
    {
        Student_Course_Home(Course_pos, pos);
        return;
    }
    // Come Back
    Student_Course_Home(Course_pos, pos);
    return;
}
void  System_Flow :: Announcments(int Course_pos, int pos)
{
    cout << Students[pos].My_Courses[Course_pos]->Announcemnts;
    cout << endl;
    Student_Course_Home(Course_pos, pos);
}
void System_Flow ::  Disscusions(int Course_pos, int pos)
{
    cout << endl;
    cout << "1-Post" << endl;
    cout << "2-Disscusions" << endl;
    cout << "3-Back" << endl;

    int Choice;
    Get_int(Choice);

    if (Choice == 1)
    {
        // Get the Post
        Disscusion new_Disscusion;
        cout << "Post:";
        getline(cin >> ws, new_Disscusion.Post);
        new_Disscusion.Post = Students[pos].UserName + ":" + new_Disscusion.Post;
        // Add (to the Course's Discussion) a Post
        Students[pos].My_Courses[Course_pos]->Disscusions.Add(new_Disscusion);
        Disscusions(Course_pos, pos);
        return;
    }
    else if (Choice == 2)
    {
        // Print all Posts of Course and it's Reply
        cout << Students[pos].My_Courses[Course_pos]->Disscusions;
        int n = Students[pos].My_Courses[Course_pos]->Disscusions.Size();

        cout << "..........Press 0 to Back..........." << endl;

        int Choose;
        // make sure that the user will enter right Num
        while (true)
        {
            cout << "Post Num:"; Get_int(Choose);
            if (Choose <= n && Choose >= 0)
                break;
        }


        // if he Wants to Back to the Course's Home
        if (Choose == 0)
        {
            Student_Course_Home(Course_pos, pos);
            return;
        }

        // print the replys if exist
        if (Students[pos].My_Courses[Course_pos]->Disscusions[Choose - 1].Replay.Size() != 0)
        {
            // print the replys on Post
            cout << Students[pos].My_Courses[Course_pos]->Disscusions[Choose - 1].Replay;
        }

        // ......... Check if the User wants just to see replys not to Comment (you can skip it)  ..............
        int Check_Back = 1;
        cout << "..........Press 0 to Back...........any Number to comment ..............." << endl;
        Get_int(Check_Back);
        if (Check_Back == 0)
        {
            Disscusions(Course_pos, pos);
            return;
        }
        // .....................................................................................................

        cout << "Reply:";
        string reply;
        getline(cin >> ws, reply);

        ((Students[pos].My_Courses[Course_pos])->Disscusions[Choose - 1].Replay).Add(Students[pos].UserName + ":" + reply);

        Disscusions(Course_pos, pos);
        return;

    }
    else if (Choice == 3)
    {
        Student_Course_Home(Course_pos, pos);
        return;
    }
    else
    {
        Disscusions(Course_pos, pos);
        return;
    }

}
void  System_Flow :: Grade_Report(int Course_pos, int pos)
{

    int n = Students[pos].My_Courses[Course_pos]->Quizes.Size();
    for (int i = 0; i < n; i++)
    {
        // Search in each Quiz about a solution to that Student
        Solution temp;  temp.student = &Students[pos];
        int found = Students[pos].My_Courses[Course_pos]->Quizes[i].Quiz_Solutions.Find(temp);

        // if solution is not found skip it
        if (found == -1)
            continue;

        cout << "Quiz" << i+1 << "\t";
        cout << Students[pos].My_Courses[Course_pos]->Quizes[i].Quiz_Solutions[found].Grade ;
        cout << "/" << Students[pos].My_Courses[Course_pos]->Quizes[i].Max_Grade << endl;
    }
    Student_Course_Home(Course_pos, pos);
    return;
}
void  System_Flow :: UnRegister(int Course_pos, int pos)
{
    // Make sure that he hadn't enter UnRegister By Mistake
    char Check = '!';
    cout << "......Are You Sure That You Want To UnRegister ?!..... Y for Yes ..... N for No......" << endl;
    while (true)
    {
        cin >> Check;
        // if Yes Apply the Function
        if (Check == 'Y' || Check == 'y')
            break;
        // if no return to the Main Course Function
        else if (Check == 'n' || Check == 'N')
        {
            Student_Course_Home(Course_pos, pos);
            // we use return to end this function after it finished from Student_Course_Home function
            return;
        }
    }

    int n = Students[pos].My_Courses[Course_pos]->Quizes.Size();
    for (int i = 0; i < n; i++)
    {
        Solution temp;				temp.student = &Students[pos];
        Students[pos].My_Courses[Course_pos]->Quizes[i].Quiz_Solutions.Delete(temp);
    }

    Students[pos].My_Courses[Course_pos]->students.Delete(&Students[pos]);
    Students[pos].My_Courses.Delete(Students[pos].My_Courses[Course_pos]);
    Student_Home(pos);
    return;
}


// ............... Doctor .....................
void System_Flow ::  Doctor_Home(int pos)
{
    cout << endl;
    cout << "1-My Courses" << endl;
    cout << "2-Add Course" << endl;
    cout << "3-inbox" << endl;
    cout << "4-Sign out" << endl;

    int Choice;
    Get_int(Choice);

    if (Choice == 1)
        Doctor_Courses(pos);
    else if (Choice == 2)
        Add_Course(pos);
    else if (Choice == 3)
        Doctor_inbox(pos);
    else if (Choice == 4)
    {
        Get_Started();
        return;
    }
    else
        Doctor_Home(pos);

}
void System_Flow ::  Doctor_Courses(int pos)
{
    // we Can't use (cout << Doctors[pos].My_Courses;) as it prints value and we dealing here with pointers
    // (we don't need the adress we need the course it's self)
    int  n = (Doctors[pos].My_Courses).Size();
    if (n == 0)
    {
        Doctor_Home(pos);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "-" << *(Doctors[pos].My_Courses[i]);
    }

    int Choice;
    while (true)
    {
        Get_int(Choice);
        if (Choice <= n && Choice > 0)
            break;
    }
    // return to Home
    Doctor_Course_Home(Choice - 1, pos);
}
void System_Flow ::  Add_Course(int pos)
{
    // We must pass a Course in the Add function as an argument
    Course Temp;
    cout << "Name:"; cin >> Temp.Name;
    // pointer to the Course which we created in Linked_List Courses
    Course* pointer = Courses.Add(Temp);
    // Make the Course points at the Doctor
    pointer->Doctor_OF_Course = &Doctors[pos];
    // Make the Doctor have a pointer to the course
    (Doctors[pos].My_Courses).Add(pointer);

    Doctor_Home(pos);// return to Home
}

// ............... Doctor Course......................
void System_Flow ::  Doctor_Course_Home(int Course_pos, int pos)
{
    cout << endl;
    cout << *(Doctors[pos].My_Courses[Course_pos]);
    cout << "1-Add Quiz" << endl;
    cout << "2-Add Anouncment" << endl;
    cout << "3-Disscusion" << endl;
    cout << "4-Students" << endl;
    cout << "5-Back" << endl;

    int Choice;
    Get_int(Choice);

    if (Choice == 1)
        Add_Quiz(Course_pos, pos);
    else if (Choice == 2)
        Add_Anouncment(Course_pos, pos);
    else if (Choice == 3)
        Doctor_Disscusion(Course_pos, pos);
    else if (Choice == 4)
        Students_Of_Course(Course_pos, pos);
    else if (Choice == 5)
        Doctor_Home(pos);
    else
        Doctor_Course_Home(Course_pos, pos);

}
void  System_Flow :: Add_Quiz(int Course_pos, int pos)
{
    // Add Memory for Course
    Quiz New_Quiz;
    Doctors[pos].My_Courses[Course_pos]->Quizes.Add(New_Quiz);
    // Get the Questions from the Doctor and all requirment Data
    int Size;
    cout << "Number of Questions:"; cin >> Size;
    Doctors[pos].My_Courses[Course_pos]->Quizes[-1].Add_Questions(Size);
    // cin Quiz >>>> cin all Questions >>>> cin one Question
    cin >> Doctors[pos].My_Courses[Course_pos]->Quizes[-1];
    // After we Get the Questions and its marks we add them to get the Max_Grade of Quiz
    Doctors[pos].My_Courses[Course_pos]->Quizes[-1].Set_Max_Grade();
    Doctor_Course_Home(Course_pos, pos);
}
void System_Flow ::  Add_Anouncment(int Course_pos, int pos)
{
    string Doctor_Announcemnt;
    cout << " Announcemnts:"; getline(cin >> ws, Doctor_Announcemnt);
    Doctors[pos].My_Courses[Course_pos]->Announcemnts.Add(Doctor_Announcemnt);
    Doctor_Course_Home(Course_pos, pos);
}
void System_Flow ::  Doctor_Disscusion(int Course_pos, int pos)
{
    cout << "1-Disscusions" << endl;
    cout << "2-Back" << endl;

    int Choice;
    Get_int(Choice);

    if (Choice == 1)
    {

        int n = Doctors[pos].My_Courses[Course_pos]->Disscusions.Size();
        if (n == 0)
        {
            Doctor_Course_Home(Course_pos, pos);
            return;
        }
        // Print all Posts of Course
        cout << Doctors[pos].My_Courses[Course_pos]->Disscusions;

        cout << "..........Press 0 to Back..........." << endl;

        int Choose;
        // make sure that the user will enter right Num
        while (true)
        {
            Get_int(Choose);
            if (Choose <= n && Choose >= 0)
                break;
        }
        // if he Wants to Back to the Course's Home
        if (Choose == 0)
        {
            Doctor_Course_Home(Course_pos, pos);
            return;
        }

        // print the replys on Post
        cout << Doctors[pos].My_Courses[Course_pos]->Disscusions[Choose - 1].Replay;

        // ......... Check if the User wants just to see replys not to Comment ..............
        int Check_Back = 1;
        cout << "..........Press 0 to Back...........any Number to comment ..............." << endl;
        Get_int(Check_Back);
        if (Check_Back == 0)
        {
            Doctor_Disscusion(Course_pos, pos);
            return;
        }
        // ....................................................................................

        cout << "Reply:";
        string reply;
        getline(cin>>ws, reply);

        Doctors[pos].My_Courses[Course_pos]->Disscusions[Choose - 1].Replay.Add(Doctors[pos].UserName + ":" + reply);
        Doctor_Disscusion(Course_pos, pos);
        return;

    }
    else if (Choice == 2)
    {
        Doctor_Course_Home(Course_pos, pos);
        return;
    }
    else
    {
        Doctor_Disscusion(Course_pos, pos);
        return;
    }

}
void  System_Flow :: Students_Of_Course(int Course_pos, int pos)
{
    int n = (Doctors[pos].My_Courses[Course_pos])->students.Size();
    for (int i = 0; i < n; i++)
    {
        cout << *(Doctors[pos].My_Courses[Course_pos]->students[i]);
    }
    Doctor_Course_Home(Course_pos, pos);
}

// ..............inbox.................................
void  System_Flow :: Doctor_inbox(int pos)
{
    cout << endl;
    cout << "1-My Messeges" << endl;
    cout << "2-Send Messege to Student" << endl;
    cout << "3-Send Message to Doctor" << endl;
    cout << "4-Back" << endl;

    int Choice;
    while (true)
    {
        Get_int(Choice);
        if (Choice <= 4 && Choice > 0)
            break;
    }

    if (Choice == 1)
    {
        if (Doctors[pos].inbox.Size() == 0)
        {
            Doctor_inbox(pos);
            return;
        }
        cout << Doctors[pos].inbox;
        Doctor_inbox(pos);
        return;
    }
    else if (Choice == 2)
    {
        Helpfull_FOR_inbox(Doctors[pos].UserName, 2 , "Doctor" , pos);
        Doctor_inbox(pos);
        return;
    }
    else if (Choice == 3)
    {
        Helpfull_FOR_inbox(Doctors[pos].UserName, 3, "Doctor", pos);
        Doctor_inbox(pos);
        return;
    }
    else if (Choice == 4)
    {
        Doctor_Home(pos);
        return;
    }

}
void  System_Flow :: Student_inbox(int pos)
{
    cout << "1-My Messeges" << endl;
    cout << "2-Send Messege to Student" << endl;
    cout << "3-Send Message to Doctor" << endl;
    cout << "4-Back" << endl;

    int Choice;
    while (true)
    {
        Get_int(Choice);
        if (Choice <= 4 && Choice > 0)
            break;
    }

    if (Choice == 1)
    {
        if (Students[pos].inbox.Size() == 0)
        {
            Student_inbox(pos);
            return;
        }
        cout << Students[pos].inbox;
        Student_inbox(pos);
        return;
    }
    else if (Choice == 2)
    {
        Helpfull_FOR_inbox(Students[pos].UserName, 2 , "Student" , pos);
        Student_inbox(pos);
        return;
    }
    else if (Choice == 3)
    {
        Helpfull_FOR_inbox(Students[pos].UserName, 3, "Student", pos);
        Student_inbox(pos);
        return;
    }
    else if (Choice == 4)
    {
        Student_Home(pos);
        return;
    }
}
void System_Flow ::  Helpfull_FOR_inbox(string Name_Send, int Choice ,string Doctor_OR_Student , int pos)
{
    if (Choice == 2)
    {
        // Get the Name you will Send
        string name;
        cout << "Name:"; cin >> name;
        int Send_to = -1;
        // Search if he exists
        for (int i = 0, n = Students.Size(); i < n; i++)
        {
            if (Students[i].UserName == name)
            {
                // if found make Send_to the position of the founded Student
                Send_to = i;
                break;
            }
        }
        // if it is found
        if (Send_to != -1)
        {
            // if it found read his Message
            string Messege;
            cout << "Message:"; cin >> Messege;
            // Name of Sender: Message content
            Students[Send_to].inbox.Add(Name_Send + " : " + Messege);
        }
    }
    else if (Choice == 3)
    {
        // Get the Name You will Sent to
        string name;
        cout << "Name:"; cin >> name;
        int Send_to = -1;
        for (int i = 0, n = Doctors.Size(); i < n; i++)
        {
            if (Doctors[i].UserName == name)
            {
                // if found make Send_to the position of the founded Doctor
                Send_to = i;
                break;					}
        }
        // if it is found
        if (Send_to != -1)
        {
            // if it found read his Message
            string Messege;
            cout << "Message:"; cin >> Messege;
            // Name of Sender: Message content
            Doctors[Send_to].inbox.Add(Name_Send + " : " + Messege);
        }
    }
    if (Doctor_OR_Student == "Doctor")
    {
        Doctor_inbox(pos);
        return;
    }
    else if (Doctor_OR_Student == "Student")
    {
        Student_inbox(pos);
        return;
    }
}


void  System_Flow :: DymmyData()
{
    ifstream file(dummy_path.toStdString());
    if (!file.is_open())
    {
        cout << "file msh ray2 Can't open" << endl;
        exit(1);
    }

    string first_word;

    while (file >> first_word)
    {
        if (first_word == "Doctor")
        {
            int id; string  pas, name, email; 			string first, first_ann, seconed, seconed_ann;
            file >> id >> pas >> email >> name >> first >> first_ann >> seconed >> seconed_ann;

            Doctor temp;
            temp.UserName = name; temp.Email = email; temp.ID = id; temp.Password = pas;
            Doctors.Add(temp);

            Course FIRST, SECONED;
            FIRST.Name = first;
            SECONED.Name = seconed;

            Courses.Add(FIRST);
            Doctors[-1].My_Courses.Add(&Courses[-1]);
            Courses[-1].Announcemnts.Add(first_ann);
            Courses[-1].Doctor_OF_Course = &Doctors[-1];

            Courses.Add(SECONED);
            Doctors[-1].My_Courses.Add(&Courses[-1]);
            Courses[-1].Announcemnts.Add(seconed_ann);
            Courses[-1].Doctor_OF_Course = &Doctors[-1];
        }
        else if (first_word == "Student")
        {
            int id; string  pas, name, email;		string first, seconed, third;
            file >> id >> pas >> email >> name >> first >> seconed >> third;

            Student temp;
            temp.UserName = name; temp.Email = email; temp.ID = id; temp.Password = pas;
            Students.Add(temp);

            Course Temp;
            int pos;

            Temp.Name = first;
            pos = Courses.Find(Temp);
            Students[-1].My_Courses.Add(&Courses[pos]);
            Courses[pos].students.Add(&Students[-1]);

            Temp.Name = seconed;
            pos = Courses.Find(Temp);
            Students[-1].My_Courses.Add(&Courses[pos]);
            Courses[pos].students.Add(&Students[-1]);

            Temp.Name = third;
            pos = Courses.Find(Temp);
            Students[-1].My_Courses.Add(&Courses[pos]);
            Courses[pos].students.Add(&Students[-1]);

        }
        else if (first_word == "Student_Discussion")
        {
            int id; string pas , course_name, diss_post ;
            file >> id >> pas >> course_name >> diss_post;

            Student temp; temp.ID = id; temp.Password = pas;
            Course Temp; Temp.Name = course_name;

            int course_pos = Courses.Find(Temp);
            int pos = Students.Find(temp);

            Disscusion new_Disscusion;
            new_Disscusion.Post = Students[pos].UserName + ":" + diss_post;

            Courses[course_pos].Disscusions.Add(new_Disscusion);
        }
    }


    file.close();
}
 System_Flow :: System_Flow(QString path)
{
    this->dummy_path = path;
    DymmyData();
    Get_Started();
}
 System_Flow :: ~System_Flow()
{
    cout << "Tari2 Elsalama enta" << endl;
}


