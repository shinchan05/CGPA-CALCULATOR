/*
Project: Advanced CGPA Calculator
Description:
A menu-driven C++ program to calculate CGPA using credit-based system.
Supports subject names, grade validation, and formatted output.
*/

#include<iostream>
#include <cctype>
using namespace std;

int getgrade(char grade)
{
    if (grade == 'A'|| grade == 'a')
    return 10;
    else if (grade == 'B'||grade == 'b')
    return 8;
    else if (grade == 'C' ||grade == 'c')
    return 6;
    else if (grade == 'D'||grade == 'd')
    return 4;
    else return 0;
}

int main()
{
    while(1)
    {
    int n;
    cout<<"Enter no.of subjects"<<endl;
    cin>>n;
    string studentname;
        cout << "Enter student name: ";
        cin.ignore();  
        getline(cin, studentname);
    float total_points = 0;
    int total_credits = 0;
     char grade;
    string subjects[100];
    char grades[100];
    int credits[100];
    int points[100];
   
   
    for(int i=0;i<n;i++)
     {

        string subject;
        cout<<"enter subject name"<<endl;
        cin.ignore();
            getline(cin, subject);
        //cin>>subject;
        cout<<"Enter the grade of subject "<<i+1<<endl;
        cin>>grade;
        
        grade = toupper(grade);
        
        if (grade != 'A' && grade != 'B' && grade != 'C' && grade != 'D')
            {
                cout << "Invalid grade! Enter again.\n";
                i--;
                continue;
            }
            int credit;
            cout << "Enter credit for subject " << i+1 << endl;
            cin >> credit;
       
        int point = getgrade(grade);
        total_points += point * credit;
        total_credits += credit;
        subjects[i] = subject;
        grades[i] = grade;
        credits[i] = credit;
        points[i] = point * credit;
     }
     float cgpa = total_points / total_credits;
     cout << "\nStudent Name: " << studentname << endl;
     cout << "\n-------------------------------------------\n";
        cout << "Subject\tGrade\tCredit\tPoints\n";
        cout << "-------------------------------------------\n";

        for(int i = 0; i < n; i++)
        {
            cout << subjects[i] << "\t"
                << grades[i] << "\t"
                << credits[i] << "\t"
                << points[i] << endl;
        }

        cout << "-------------------------------------------\n";

        cout << "CGPA is " << cgpa << endl;
     char choice;
        cout << "Do you want to calculate again? (y/n): ";
        cin >> choice;

        if (choice == 'n' || choice == 'N')
            break;
    }
     return 0;
}
