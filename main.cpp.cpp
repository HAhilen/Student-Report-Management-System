//Student Management system
#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <string_view>
#include <regex>
#include <stdio.h>
#include<iomanip>
#include<windows.h>

using namespace std;
//Email verification
bool Emailcheck(string email)
{
    const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return regex_match(email,pattern);
}
//Roll format verification
bool rollCheck(string roll)
{
    const regex pattern("[0-9]{1,3}");
    return regex_match(roll,pattern);
}
//Phone verification
bool Phonecheck(string contact)
{
    const regex pattern("[9][\\d]{9}");
    return regex_match(contact,pattern);
}
class student
{
private:
    string first_name,last_name,course,address,email_id,contact_no,firstName,roll_no,id,profession,grade,passcode,feedback;
    int marks[5],totalmarks=0;
    float percent;

public:
    void check();
    void studentstaff();
    void menu();
    void log_in();
    void general();
    void academic();
    void insertGeneral();
    void displayGeneral();
    void modifyGeneral();
    void searchGeneral();
    void deletedGeneral();
    void insertAcademic();
    void displayAcademic();
    void modifyAcademic();
    void searchAcademic();
    void deletedAcademic();
    void userStudent();
    string gradeof();
    void Feedback();
    void viewStudent();
    void viewAcademic();
    void viewFeedback();
};

//Entry Page
void student::check()
{
login:
    string user_name;
    int z;
    system("cls");
    system("color a");
    cout<< "\t\t\t=========================================================================================================" << endl;
    cout<< "\t\t\t||                              STUDENT RECORD MANAGEMENT SYSTEM                                        ||" << endl;
    cout<< "\t\t\t=========================================================================================================" << endl;
    cout<< "\t\t\t                           >>>>Log In To STUDENT MANAGEMENT SYSTEM <<<<"<< endl;
    cout<< "\t\t\t                                      ::ENTRY PAGE::"<<endl;
    cout<< "\t\t\tUser Type:";
    cin>>user_name;

    if(user_name=="student"||user_name=="Student"||user_name=="STUDENT")
    {
        userStudent();
    }
    else if (user_name=="admin"||user_name=="Admin"||user_name=="ADMIN")
    {
        menu();
    }

    else
    {
        cout<< "\n\t\t\tWrong user type !!!\n\t\t\tPress any key to continue."<<endl;
    }
    getch();
    goto login;
}

//ADMIN LOGIN PAGE
void student:: menu()
{
menustart:
    string password;
    char x;
    system("cls");
    cout<< "\t\t\t=========================================================================================================" << endl;
    cout<< "\t\t\t||                              STUDENT RECORD MANAGEMENT SYSTEM                                        ||" << endl;
    cout<< "\t\t\t=========================================================================================================" << endl;
    cout<< "\t\t\t                                      ::ADMIN PAGE:: " << endl;
    cout<< "\t\t\tPassword:";
    cin>>password;

    if (password=="admin"||password=="Admin"||password=="ADMIN")
    {
        studentstaff();
    }

    else
    {
        cout<< "\n\t\t\tWrong password !!!\n\t\t\tPress any key twice to  continue in 'ENTRY PAGE'.\n\t\t\tEnter User type as student if you don't have password !!!"<<endl;
    }
    getch();
}

//ADMIN PAGE
void student::studentstaff()
{
StudentStaff:
    int choice;
    char x;
    system("cls");
    cout<< "\t\t\t=========================================================================================================" << endl;
    cout<< "\t\t\t||                              STUDENT RECORD MANAGEMENT SYSTEM                                        ||" << endl;
    cout<< "\t\t\t=========================================================================================================" << endl;
    cout<< "\t\t\t                                         ::Admin PAGE:: " << endl;
    cout<< "\t\t\t 1.General Record" << endl;
    cout<< "\t\t\t 2.Academic Record" << endl;
    cout<< "\t\t\t 3.View Student's Feedback"<<endl;
    cout<< "\t\t\t 4.Go to Entry Page" << endl;
    cout<< "\t\t\t 5.Exit";
choice:
    {
        cout<< "\n\t\t\tEnter your option:";
        cin>>choice;
    }
    switch(choice)
    {
    case 1:
        general();
        break;
    case 2:
        academic();
        break;
    case 3:
        viewFeedback();
        break;
    case 4:
        check();
        break;
    case 5:
        cout << "\n\t\t\tDO you want to exit?\n\t\t\t(y/n):";
        cin>>x;
        while(x=='y'||x=='Y')
        {
            cout<< "\n\t\t\tThank You :)\n\n\n\n";
            exit(0);
        }
        break;
    default:
        cout<< "\n\t\t\tInvalid choice...Please try again..";
        goto StudentStaff;
    }
    getch();
    goto StudentStaff;
}
//General Record
void student:: general()
{
menustart:
    int choice;

    char x;
    system("cls");
    cout<< "\t\t\t=========================================================================================================" << endl;
    cout<< "\t\t\t||                              STUDENT RECORD MANAGEMENT SYSTEM                                        ||" << endl;
    cout<< "\t\t\t=========================================================================================================" << endl;
    cout<< "\t\t\t                                     ::GENERAL RECORD::" << endl;

    cout<< "\t\t\t 1.Add new record" << endl;
    cout<< "\t\t\t 2.View record" << endl;
    cout<< "\t\t\t 3.Modify record" << endl;
    cout<< "\t\t\t 4.Search record" << endl;
    cout<< "\t\t\t 5.Delete record" << endl;
    cout<< "\t\t\t 6.Go Back" << endl;
    cout<< "\t\t\t=============================" << endl;
    cout<< "\t\t\t|Choose option [1/2/3/4/5/6]|" << endl;
    cout<< "\t\t\t=============================" << endl;
choice:
    {
        cout<< "\t\t\tEnter your option:";
        cin>>choice;
    }
    switch(choice)
    {
    case 1:
        do
        {
            insertGeneral();
            cout << "\n\t\t\tAdd another student record?\n\t\t\t(y/n):";
            cin>>x;
        }
        while(x=='y'||x=='Y');
        break;
    case 2:
        displayGeneral();
        break;
    case 3:
        do
        {
            modifyGeneral();
            cout << "\n\t\t\tModify another student record?\n\t\t\t(y/n):";
            cin>>x;
        }
        while(x=='y'||x=='Y');
        break;
    case 4:
        do
        {
            searchGeneral();
            cout << "\n\t\t\tSearch another student record?\n\t\t\t(y/n):";
            cin>>x;
        }
        while(x=='y'||x=='Y');
        break;
    case 5:
        do
        {
            deletedGeneral();
            cout << "\n\t\t\tDelete another student record(y/n):";
            cin>>x;
        }
        while(x=='y'||x=='Y');
        break;
    case 6:
        studentstaff();
    default:
        cout<< "\n\t\t\tInvalid choice...Please try again..";
    }
    getch();
    goto menustart;
}
//Academic Record
void student:: academic()
{
menustart:
    int choice;
    char x;
    system("cls");
    cout<< "\t\t\t=========================================================================================================" << endl;
    cout<< "\t\t\t||                              STUDENT RECORD MANAGEMENT SYSTEM                                        ||" << endl;
    cout<< "\t\t\t=========================================================================================================" << endl;
    cout<< "\t\t\t                                    ::ACADEMIC RECORD:: " << endl;

    cout<< "\t\t\t 1.Add new record" << endl;
    cout<< "\t\t\t 2.View record" << endl;
    cout<< "\t\t\t 3.Modify record" << endl;
    cout<< "\t\t\t 4.Search record" << endl;
    cout<< "\t\t\t 5.Delete record" << endl;
    cout<< "\t\t\t 6.Go Back" << endl;
    cout<< "\t\t\t=============================" << endl;
    cout<< "\t\t\t|Choose option [1/2/3/4/5/6]|" << endl;
    cout<< "\t\t\t=============================" << endl;
choice:
    {
        cout<< "\t\t\tEnter your option:";
        cin>>choice;
    }
    switch(choice)
    {
    case 1:
        do
        {
            insertAcademic();
            cout << "\n\t\t\tAdd another student record?\n\t\t\t(y/n):";
            cin>>x;
        }
        while(x=='y'||x=='Y');
        break;
    case 2:
        displayAcademic();
        break;
    case 3:
        do
        {
            modifyAcademic();
            cout << "\n\t\t\tModify another student record?\n\t\t\t(y/n):";
            cin>>x;
        }
        while(x=='y'||x=='Y');
        break;
    case 4:
        do
        {
            searchAcademic();
            cout << "\n\t\t\tSearch another student record?\n\t\t\t(y/n):";
            cin>>x;
        }
        while(x=='y'||x=='Y');
        break;
    case 5:
        do
        {
            deletedAcademic();
            cout << "\n\t\t\tDelete another student record(y/n):";
            cin>>x;
        }
        while(x=='y'||x=='Y');
        break;
    case 6:
        studentstaff();
    default:
        cout<< "\n\t\t\tInvalid choice...Please try again..";
        goto menustart;
    }
    getch();
    goto menustart;
}
//Student Page
void student::userStudent()
{
user:
    int choice;
    char x;
    system("cls");
    cout<< "\t\t\t=========================================================================================================" << endl;
    cout<< "\t\t\t||                              STUDENT RECORD MANAGEMENT SYSTEM                                        ||" << endl;
    cout<< "\t\t\t=========================================================================================================" << endl;
    cout<< "\t\t\t                                       ::STUDENT PAGE:: " << endl;
    cout<< "\t\t\t 1.View Record" << endl;
    cout<< "\t\t\t 2.Feedback" << endl;
    cout<< "\t\t\t 3.Go to Entry Page"<<endl;
    cout<< "\t\t\t 4.Exit" << endl;
    cout<< "\t\t\t=======================" << endl;
    cout<< "\t\t\t|Choose option [1/2/3]|" << endl;
    cout<< "\t\t\t=======================" << endl;
    cout<< "\t\t\tEnter your option:";
    cin>>choice;

    switch(choice)
    {
    case 1:
        viewStudent();
        break;
    case 2:
        Feedback();
        break;
    case 3:
        check();
        break;

    case 4:
        cout << "\n\t\t\tDO you want to exit?\n\t\t\t(y/n):";
        cin>>x;
        while(x=='y'||x=='Y')
        {
            cout<< "\n\t\t\tThank You :)\n\n\n\n";
            exit(0);
        }
        break;
    default:
        cout<< "\n\t\t\tInvalid choice...Please try again..";
        break;
    }
    getch();
    goto user;
}

//to take feedback from student
void student::Feedback()
{
    system("cls");
    fstream file;
    file.open("feedback.txt",ios::app|ios::out);
    cout<< "\t\t\t=========================================================================================================" << endl;
    cout<< "\t\t\t||                              STUDENT RECORD MANAGEMENT SYSTEM                                        ||" << endl;
    cout<< "\t\t\t=========================================================================================================" << endl;
    cout<< "\t\t\t                                        ::FEEDBACK:: " << endl;
    cin.ignore();
    cout<<"\t\t\tRollNo/Give your Feedback::";
    getline(cin,feedback);
    file<<feedback<<endl;
    file.close();
}
//view both academic and general record
void student::viewStudent()
{
record:
    system("cls");
    int choice;
    cout<< "\t\t\t=========================================================================================================" << endl;
    cout<< "\t\t\t||                              STUDENT RECORD MANAGEMENT SYSTEM                                        ||" << endl;
    cout<< "\t\t\t=========================================================================================================" << endl;
    cout<< "\t\t\t                                    ::VIEW RECORD PAGE:: " << endl;
    cout<< "\t\t\t 1.View General Record" << endl;
    cout<< "\t\t\t 2.View Academic Record" << endl;
    cout<< "\t\t\t 3.Go Back" << endl;
    cout<< "\t\t\t   =======================" << endl;
    cout<< "\t\t\t   |Choose option [1/2/3]|" << endl;
    cout<< "\t\t\t   =======================" << endl;
    cout<<"\t\t\t Enter your choice:";
    cin>>choice;
    switch(choice)
    {
    case 1:
        displayGeneral();
        break;
    case 2:
        viewAcademic();
        break;
    case 3:
        userStudent();
    default:
        cout<< "Invalid choice";
        break;
    }
    getch();
    goto record;
}
//view own academic record
void student::viewAcademic()
{
    system("cls");
    int totalmarks=0;
    fstream file;
    string password;
    cout<< "\t\t\t=========================================================================================================" << endl;
    cout<< "\t\t\t||                              STUDENT RECORD MANAGEMENT SYSTEM                                        ||" << endl;
    cout<< "\t\t\t=========================================================================================================" << endl;
    cout<< "\t\t\t                                   ::STUDENT ACADEMIC RECORD::"<<endl;
    file.open("academicRecord.txt",ios::in);
    cout<< "\t\t\tPassword:";
    cin>>password;
    file>>roll_no>>passcode>>marks[0]>>marks[1]>>marks[2]>>marks[3]>>marks[4]>>totalmarks>>grade;
    while(!file.eof())
    {

        if (password==passcode)
        {
            system("cls");
            cout<< "\t\t\t=========================================================================================================" << endl;
            cout<< "\t\t\t||                              STUDENT RECORD MANAGEMENT SYSTEM                                        ||" << endl;
            cout<< "\t\t\t=========================================================================================================" << endl;
            cout<< "\t\t\t                                   ::STUDENT ACADEMIC RECORD::"<<endl;
            cout<<"\t\t\t"<<setw(9)<<"Roll no"<<setw(10)<<"Passcode"<<setw(12)<<"Subject1"<<setw(11)<<"Subject2"<<setw(11)<<"Subject3"<<setw(11)<<"Subject4"<<setw(11)<<"Subject5"<<setw(11)<<"Total"<<setw(9)<<"Grade";
            cout<<"\n";
            cout<<"\t\t\t"<<setw(9)<<roll_no<<setw(10)<<passcode<<setw(10)<<marks[0]<<setw(11)<<marks[1]<<setw(11)<<marks[2]<<setw(11)<<marks[3]<<setw(11)<<marks[4]<<setw(12)<<totalmarks<<setw(8)<<grade;
            cout<<"\n";
        }
        file>>roll_no>>passcode>>marks[0]>>marks[1]>>marks[2]>>marks[3]>>marks[4]>>totalmarks>>grade;

    }
    if(password!=passcode)
    {
        cout<< "\n\t\t\tWrong password !!!\n\t\t\tPress any key twice to  continue"<<endl;
    }

    cout<< "\n\t\t\tPress any key to continue...."<<endl;
    file.close();

}

//Insert general records
void student::insertGeneral()
{
    system("cls");
    string rollno;
    fstream file;
    cout<< "\t\t\t=========================================================================================================" << endl;
    cout<< "\t\t\t||                              STUDENT RECORD MANAGEMENT SYSTEM                                        ||" << endl;
    cout<< "\t\t\t=========================================================================================================" << endl;
    cout<< "\t\t\t                                    ::ADD STUDENT DETAILS::"<<endl;
    cin.ignore();
    cout<< "\n\t\t\tEnter First Name   : ";
    getline(cin,first_name);
    cout<< "\t\t\tEnter Last Name    : ";
    getline(cin,last_name);
roLL:
    cout<< "\t\t\tEnter Roll no.     : ";
    cin>>roll_no;
    if(rollCheck(roll_no))
    {
        cout<<" ";
    }
    else
    {
        cout<<"\t\t\tinvalid roll format !!\n";
        goto roLL;
    }
    cin.ignore();
    cout<< "\t\t\tEnter course       : ";
    getline(cin,course);
email:
    cout<<"\t\t\tEnter your Email-Id: ";
    cin>>email_id;
    if(Emailcheck(email_id))
    {
        cout<<" ";
    }
    else
    {
        cout<<"\t\t\tYour Email-Id is invalid !!! Pleased try again !!! \n"<<endl;
        goto email;
    }
contact:
    cout<< "\t\t\tEnter Contact no(10-digits only): ";
    cin>>contact_no;
    if(Phonecheck(contact_no))
    {
        cout<<" ";
    }
    else
    {
        cout<< "\t\t\tEnter valid contact number..!!!"<<endl;
        goto contact;
    }
    cin.ignore();
    cout<< "\t\t\tEnter Address      : ";
    getline(cin,address);
    file.open("studentRecord.txt",ios::app| ios::out);
    file <<first_name<<" "<<last_name<<"  "<<roll_no<<" "<<course<<" "<<email_id<<" "<<contact_no<<" "<<address<<"\n";
    file.close();
}

//Display General Function
void student::displayGeneral() //Display general records
{
    system("cls");
    fstream file;
    int total=1;
    cout<< "\t\t\t=========================================================================================================" << endl;
    cout<< "\t\t\t||                              STUDENT RECORD MANAGEMENT SYSTEM                                        ||" << endl;
    cout<< "\t\t\t=========================================================================================================" << endl;
    cout<< "\t\t\t                                   ::STUDENT RECORD TABLE::"<<endl;
    file.open("studentRecord.txt",ios::in);
    if(!file)
    {
        cout<< "\n\t\t\tNo data is present...";
        file.close();
    }
    else
    {
        file>>first_name>>last_name>>roll_no>>course>>email_id>>contact_no>>address;
        cout<<"\t\t\t"<<setw(5)<<"S.N."<<setw(25)<<"Student Name"<<setw(10)<<"Roll No"<<setw(10)<<"Course"<<setw(25)<<"E-mail"<<setw(15)<<"Phone"<<setw(15)<<"Address";
        cout<<"\n\t\t\t--------------------------------------------------------------------------------------------------------\n";
        while(!file.eof())
        {
            cout<<"\t\t\t"<<setw(5)<<total++<<setw(25)<<first_name+" "+last_name<<setw(10)<<roll_no<<setw(10)<<course<<setw(25)<<email_id<<setw(15)<<contact_no<<setw(15)<<address;
            cout<<endl;
            file>>first_name>>last_name>>roll_no>>course>>email_id>>contact_no>>address;
        }
        if(total==1)
        {
            cout<< "\n\t\t\tNo data is present...."<<endl;
        }
        cout<< "\n\t\t\tPress any key to continue...."<<endl;
    }
    file.close();
}

//Modify General Function
void student::modifyGeneral() // Modify general records
{
    system("cls");
    fstream file, file1;
    string rollno;
    int found = 0;
    cout<< "\t\t\t=========================================================================================================" << endl;
    cout<< "\t\t\t||                              STUDENT RECORD MANAGEMENT SYSTEM                                        ||" << endl;
    cout<< "\t\t\t=========================================================================================================" << endl;
    cout<< "\t\t\t                                   ::MODIFY STUDENT RECORD::"<<endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
    }
    else
    {
        cout << "\n\t\t\tEnter Roll No.: ";
        cin >> rollno;
        file1.open("record.txt", ios::app | ios::out);
        file >> first_name>>last_name >> roll_no >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            if (rollno != roll_no)

                file1 << " " << first_name<<" "<<last_name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
            else
            {
                cin.ignore();
                cout<< "\n\t\t\tEnter First Name   : ";
                getline(cin,first_name);
                cout<< "\t\t\tEnter Last Name    : ";
                getline(cin,last_name);
roLL:
                cout<< "\t\t\tEnter Roll no.     : ";
                cin>>roll_no;
                if(rollCheck(roll_no))
                {
                    cout<<" ";
                }
                else
                {
                    cout<<"\t\t\tinvalid roll format !!\n";
                    goto roLL;
                }
                cin.ignore();
                cout<< "\t\t\tEnter course       : ";
                getline(cin,course);
email:
                cout<<"\t\t\tEnter your Email-Id: ";
                cin>>email_id;
                if(Emailcheck(email_id))
                {
                    cout<<" ";
                }
                else
                {
                    cout<<"\t\t\tYour Email-Id is invalid !!! Pleased try again !!! \n"<<endl;
                    goto email;
                }
contact:
                cout<< "\t\t\tEnter Contact no(10-digits only): ";
                cin>>contact_no;
                if(Phonecheck(contact_no))
                {
                    cout<<" ";
                }
                else
                {
                    cout<< "\t\t\tEnter valid contact number..!!!"<<endl;
                    goto contact;
                }
                cin.ignore();
                cout<< "\t\t\tEnter Address      : ";
                getline(cin,address);
                file1 << " " << first_name<<" "<<last_name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
                found++;
            }
            file >> first_name>> last_name >> roll_no >> course >> email_id >> contact_no >> address;

        }
        if (found == 0)
        {
            cout << "\n\n\t\t\t Student Roll No. Not Found....";
        }
        file1.close();
        file.close();
        remove("studentRecord.txt");
        rename("record.txt", "studentRecord.txt");
    }
}

//Search General Function
void student::searchGeneral()//search general records
{
    system("cls");
    fstream file;
    int found=0;
    file.open("studentRecord.txt",ios::in);
    if(!file)
    {
        cout<< "\t\t\t=========================================================================================================" << endl;
        cout<< "\t\t\t||                              STUDENT RECORD MANAGEMENT SYSTEM                                        ||" << endl;
        cout<< "\t\t\t=========================================================================================================" << endl;
        cout<< "\t\t\t                                  ::SEARCH STUDENT DETAILS::"<<endl;

        cout << "\n\t\t\tNo data is present..."<<endl;
    }
    else
    {
        string rollno;
        cout<< "\t\t\t=========================================================================================================" << endl;
        cout<< "\t\t\t||                              STUDENT RECORD MANAGEMENT SYSTEM                                        ||" << endl;
        cout<< "\t\t\t=========================================================================================================" << endl;
        cout<< "\t\t\t                                  ::SEARCH STUDENT DETAILS::"<<endl;
        cout << "\n\t\t\tEnter roll no.:";
        cin>>rollno;
        file>>first_name>>last_name>>roll_no>>course>>email_id>>contact_no>>address;
        while(!file.eof())
        {
            if(rollno==roll_no)
            {
                cout<< "\n\t\t\t Name       : "<<first_name+" "+last_name<<endl;
                cout<< "\t\t\t Roll no    : "<<roll_no<<endl;
                cout<< "\t\t\t Course     : "<<course<<endl;
                cout<< "\t\t\t Email id   : "<<email_id<<endl;
                cout<< "\t\t\t Contact no : "<<contact_no<<endl;
                cout<< "\t\t\t Address    : "<<address<<endl;
                found++;
            }
            file>>first_name>>last_name>>roll_no>>course>>email_id>>contact_no>>address;
        }
        if(found==0)
        {
            cout<< "\n\t\t\tRoll no. not found...\nPress any key to continue...";
        }
        file.close();
    }
}

//Delete General function
void student::deletedGeneral()//Delete general records
{
    system("cls");
    fstream file,file1;
    int found=0;
    string roll;
    cout<< "\t\t\t=========================================================================================================" << endl;
    cout<< "\t\t\t||                              STUDENT RECORD MANAGEMENT SYSTEM                                        ||" << endl;
    cout<< "\t\t\t=========================================================================================================" << endl;
    cout<< "\t\t\t                                  ::DELETE STUDENT DETAILS::"<<endl;
    file.open("studentRecord.txt",ios::in);
    if(!file)
    {
        cout << "\n\t\t\tNo data is present..."<<endl;
        file.close();
    }
    else
    {
        cout << "\n\t\t\tEnter roll no.:";
        cin>>roll;
        file1.open("record.txt",ios::app|ios::out);
        file>>first_name>>last_name>>roll_no>>course>>email_id>>contact_no>>address;
        while(!file.eof())
        {
            if(roll!=roll_no)
            {
                file1<<" "<<first_name<<" "<<last_name<<" "<<roll_no<<" "<<course<<" "<<email_id<<" "<<address<<" "<<contact_no<<endl;
            }
            else
            {
                found++;
                cout<< "\n\t\t\t Student data successfully deleted...";
            }
            file>>first_name>>last_name>>roll_no>>course>>email_id>>address>>contact_no;
        }
        if(found==0)
        {
            cout<< "\n\t\t\t Student Roll no not found...\nPress any key to continue...";
        }

        file1.close();
        file.close();
        remove("studentRecord.txt");
        rename("record.txt","studentRecord.txt");
    }
}

//Insert Academic Function
void student::insertAcademic()//add academic records
{
    system("cls");
    fstream file1;
    int j=0;
    int total=0;
    cout<< "\t\t\t=========================================================================================================" << endl;
    cout<< "\t\t\t||                              STUDENT RECORD MANAGEMENT SYSTEM                                        ||" << endl;
    cout<< "\t\t\t=========================================================================================================" << endl;
    cout<< "\t\t\t                                ::ADD STUDENT ACADEMIC DETAILS::"<<endl;
    cin.ignore();
    cout<< "\n\t\t\tEnter Details:::"<<endl;
roLL:
    cout<< "\t\t\tEnter Roll no.  :";
    cin>>roll_no;
    if(rollCheck(roll_no))
    {
        cout<<" ";
    }
    else
    {
        cout<<"\t\t\tinvalid roll format !!\n";
        goto roLL;
    }
    cin.ignore();
    cout<< "\t\t\tPasscode        :";
    getline(cin,passcode);
    for(int i=0; i<=4; i++)
    {
up:
        cout<<"\t\t\tSubject"<<i+1<<" Marks  :";
        cin>>marks[i];
        if(marks[i]<=100)
        {
            cout<<" ";
        }
        else
        {
            cout<<"\t\t\tPlease enter marks between(0-100)\n";
            goto up;
        }
    }
    while(j<5)
    {
        total=total+marks[j];
        totalmarks=total;
        j++;
    }
    percent=(totalmarks/5);
    grade=gradeof();
    file1.open("academicRecord.txt",ios::app| ios::out);
    file1 <<roll_no <<" "<<passcode<<" "<<marks[0]  <<"  "<<marks[1] <<" "<<marks[2] <<" "<<marks[3]  <<" "<<marks[4]  <<" "<<totalmarks <<" "<<grade <<" "<<"\n";
    file1.close();
}

//Display Academic Function
void student::displayAcademic()//display academic records
{
    system("cls");
    fstream file1;
    int total1=1;
    cout<< "\t\t\t=========================================================================================================" << endl;
    cout<< "\t\t\t||                              STUDENT RECORD MANAGEMENT SYSTEM                                        ||" << endl;
    cout<< "\t\t\t=========================================================================================================" << endl;
    cout<< "\t\t\t                                  ::STUDENT ACADEMIC DETAILS::"<<endl;
    file1.open("academicRecord.txt",ios::in);
    if(!file1)
    {
        cout<< "\n\t\t\tNo data is present...";
        file1.close();
    }
    else
    {
        file1>>roll_no>>passcode>>marks[0]>>marks[1]>>marks[2]>>marks[3]>>marks[4]>>totalmarks>>grade;
        cout<<"\t\t\t"<<setw(9)<<"Roll no"<<setw(10)<<"Passcode"<<setw(12)<<"Subject1"<<setw(11)<<"Subject2"<<setw(11)<<"Subject3"<<setw(11)<<"Subject4"<<setw(11)<<"Subject5"<<setw(11)<<"Total"<<setw(9)<<"Grade";
        cout<<"\n";
        cout<<"\t\t\t------------------------------------------------------------------------------------------------\n"<<endl;
        while(!file1.eof())
        {
            cout<<"\t\t\t"<<setw(9)<<roll_no<<setw(10)<<passcode<<setw(10)<<marks[0]<<setw(11)<<marks[1]<<setw(11)<<marks[2]<<setw(11)<<marks[3]<<setw(11)<<marks[4]<<setw(12)<<totalmarks<<setw(8)<<grade;
            cout<<"\n";
            file1>>roll_no>>passcode>>marks[0]>>marks[1]>>marks[2]>>marks[3]>>marks[4]>>totalmarks>>grade;
            total1++;
        }
        if(total1==1)
        {
            cout<< "\n\t\t\tNo data is present...."<<endl;
        }
        cout<< "\n\t\t\tPress any key to continue...."<<endl;
    }
    file1.close();
}

//Modify Academic Function
void student::modifyAcademic() // Modify Academic records
{
    system("cls");
    fstream file, file1;
    string rollno;
    int found1= 0,j=0,total=0;
    cout<< "\t\t\t=========================================================================================================" << endl;
    cout<< "\t\t\t||                              STUDENT RECORD MANAGEMENT SYSTEM                                        ||" << endl;
    cout<< "\t\t\t=========================================================================================================" << endl;
    cout<< "\t\t\t                                  ::MODIFY ACADEMIC DETAILS::"<<endl;
    file.open("academicRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
    }
    else
    {
        cout << "\n\t\t\tEnter Roll no.:";
        cin >>rollno;
        file1.open("academic.txt", ios::app | ios::out);
        file>>roll_no>>passcode>>marks[0]>>marks[1]>>marks[2]>>marks[3]>>marks[4]>>totalmarks>>grade;
        while (!file.eof())
        {
            if (rollno!= roll_no)

                file1 <<roll_no  <<" "<<passcode<<" "<<marks[0]  <<"  "<<marks[1] <<" "<<marks[2] <<" "<<marks[3]  <<" "<<marks[4]  <<" "<<totalmarks<<" "<<grade <<" "<<"\n";
            else
            {
                for(int i=0; i<=4; i++)
                {
up:
                    cout<<"\t\t\tSubject"<<i+1<<" Marks :";
                    cin>>marks[i];
                    if(marks[i]<=100)
                    {
                        cout<<" ";
                    }
                    else
                    {
                        cout<<"\t\t\tPlease enter marks between(0-100)\n";
                        goto up;
                    }
                }
                while(j<5)
                {
                    total+=marks[j];
                    totalmarks=total;
                    j++;
                }
                percent=(totalmarks/5);
                grade=gradeof();
                file1 <<roll_no  <<" "<<passcode<<" "<<marks[0]  <<"  "<<marks[1] <<" "<<marks[2] <<" "<<marks[3]  <<" "<<marks[4]  <<" "<<totalmarks <<" "<<grade <<" "<<"\n";
                found1++;
            }
            file>>roll_no>>passcode>>marks[0]>>marks[1]>>marks[2]>>marks[3]>>marks[4]>>totalmarks>>grade;

        }
        if (found1 == 0)
        {
            cout << "\n\n\t\t\t Roll no. Not Found....";
        }
        file1.close();
        file.close();
        remove("academicRecord.txt");
        rename("academic.txt", "academicRecord.txt");
    }
}

//Search Academic Function
void student::searchAcademic()//search academic records
{
    system("cls");
    fstream file;
    int found1=0,totalmarks=0;
    file.open("academicRecord.txt",ios::in);
    if(!file)
    {
        cout<< "\t\t\t=========================================================================================================" << endl;
        cout<< "\t\t\t||                              STUDENT RECORD MANAGEMENT SYSTEM                                        ||" << endl;
        cout<< "\t\t\t=========================================================================================================" << endl;
        cout<< "\t\t\t                                  ::SEARCH ACADEMIC DETAILS::"<<endl;
        cout << "\n\t\t\tNo data is present..."<<endl;
    }
    else
    {
        string rollno;
        cout<< "\t\t\t=========================================================================================================" << endl;
        cout<< "\t\t\t||                              STUDENT RECORD MANAGEMENT SYSTEM                                        ||" << endl;
        cout<< "\t\t\t=========================================================================================================" << endl;
        cout<< "\t\t\t                                  ::SEARCH ACADEMIC DETAILS::"<<endl;
        cout << "\n\t\t\tEnter Roll no.:";
        cin>>rollno;
        file>>roll_no>>passcode>>marks[0]>>marks[1]>>marks[2]>>marks[3]>>marks[4]>>totalmarks>>grade;
        cout<<"\t\t\t"<<setw(9)<<"Roll no"<<setw(10)<<"Passcode"<<setw(12)<<"Subject1"<<setw(11)<<"Subject2"<<setw(11)<<"Subject3"<<setw(11)<<"Subject4"<<setw(11)<<"Subject5"<<setw(11)<<"Total"<<setw(9)<<"Grade";
        cout<<"\n";
        cout<<"\t\t\t------------------------------------------------------------------------------------------------\n";
        while(!file.eof())
        {
            if(rollno==roll_no)
            {
                cout<<"\t\t\t"<<setw(9)<<roll_no<<setw(10)<<passcode<<setw(10)<<marks[0]<<setw(11)<<marks[1]<<setw(11)<<marks[2]<<setw(11)<<marks[3]<<setw(11)<<marks[4]<<setw(12)<<totalmarks<<setw(8)<<grade;
                cout<<"\n";
                found1++;
            }
            file>>roll_no>>passcode>>marks[0]>>marks[1]>>marks[2]>>marks[3]>>marks[4]>>totalmarks>>grade;
        }
        if(found1==0)
        {
            cout<< "\n\t\t\tRoll No. not found...\n";
        }
        file.close();
    }
}

//Delete Academic Function
void student::deletedAcademic()//Delete academic records
{
    system("cls");
    fstream file,file1;
    int found1=0,totalmarks=0;
    string rollno;
    cout<< "\t\t\t=========================================================================================================" << endl;
    cout<< "\t\t\t||                              STUDENT RECORD MANAGEMENT SYSTEM                                        ||" << endl;
    cout<< "\t\t\t=========================================================================================================" << endl;
    cout<< "\t\t\t                                  ::DELETE ACADEMIC DETAILS::"<<endl;
    file.open("academicRecord.txt",ios::in);
    if(!file)
    {
        cout << "\n\t\t\tNo data is present..."<<endl;
        file.close();
    }
    else
    {
        cout << "\n\t\t\tEnter Roll no.:";
        cin>>rollno;
        file1.open("academic.txt",ios::app|ios::out);
        file>>roll_no>>passcode>>marks[0]>>marks[1]>>marks[2]>>marks[3]>>marks[4]>>totalmarks>>grade;
        while(!file.eof())
        {
            if(rollno!=roll_no)
            {
                file1 <<roll_no  <<" "<<passcode<<" "<<marks[0]  <<"  "<<marks[1] <<" "<<marks[2] <<" "<<marks[3]  <<" "<<marks[4]  <<" "<<totalmarks<<" "<<grade <<" "<<"\n";
            }
            else
            {
                found1++;
                cout<< "\n\t\t\t Academic Record successfully deleted...";
            }
            file>>roll_no>>passcode>>marks[0]>>marks[1]>>marks[2]>>marks[3]>>marks[4]>>totalmarks>>grade;
        }
        if(found1==0)
        {
            cout<< "\n\t\t\t Roll No. not found...";
        }
        file1.close();
        file.close();
        remove("academicRecord.txt");
        rename("academic.txt","academicRecord.txt");
    }
}
//View Student's Feedback
void student::viewFeedback()
{
    system("cls");
    fstream file;
    file.open("feedback.txt",ios::in);
    //file>>roll_no>>feedback;
    cout<< "\t\t\t=========================================================================================================" << endl;
    cout<< "\t\t\t||                              STUDENT RECORD MANAGEMENT SYSTEM                                        ||" << endl;
    cout<< "\t\t\t=========================================================================================================" << endl;
    cout<< "\t\t\t                                  ::STUDENT'S FEEDBACK::"<<endl;
    if(!file)
    {
        cout<< "\n\t\t\tNo data is present...";
        file.close();
    }
    else
    {
        getline(file,feedback);
        while(!file.eof())
        {
            cout<<"\t\t\tRollNo/FeedBack:"<<feedback;
            cout<<"\n\t\t\t----------------------------------------------------------------------------------------------------------\n";
            getline(file,feedback);
        }
    }
    file.close();
}
//Grade calculation
string student::gradeof()
{
    if(percent>=90&&percent<=100)
    {
        return "A+";
    }

    else if(percent>=80&&percent<90)
    {
        return "A";
    }
    else if(percent>=70&&percent<80)
    {
        return "B+";
    }
    else if(percent>=60&&percent<70)
    {
        return "B";
    }
    else if(percent>=50&&percent<60)
    {
        return "C+";
    }
    else if(percent>=40&&percent<50)
    {
        return "C";
    }
    else if(percent>=30&&percent<40)
    {
        return "D+";
    }
    else if(percent>=20&&percent<30)
    {
        return "D";
    }
    else
    {
        return "E";
    }

}


//Main function
int main()
{
    student project;
    project.check();
    return 0;
}
