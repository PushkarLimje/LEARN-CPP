#include <iostream>
#include <string>
using namespace std;

struct Student {
    string year;
    string division;
    string name;
    int rollNo;
};

int main()
{
   int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student students[n];

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details of student " << i+1 << ":\n";
        cout << "Year (S.Y./T.Y./B.Tech): ";
        cin >> students[i].year;
        cout << "Division: ";
        cin >> students[i].division;
        cout << "Name: ";
        cin >> students[i].name;
        cout << "Roll No: ";
        cin >> students[i].rollNo;
    } 

    string targetYear = "S.Y";
    string targetDiv  = "X";
    string targetName = "XYZ";
    int targetRoll    = 17;

    bool found =  false ;
    for (int i = 0; i < n; i++)
    {
        if (
            students[i].name == targetName && students[i].division == targetDiv && students[i].year == targetYear && students[i].rollNo == targetRoll)
        {
            std::cout << "\n\nIndex" << i <<std::endl;
            std::cout << " NAME:     "<< students[i].name << std::endl;
            std::cout << "rollNo:     "<< students[i].rollNo << std::endl;
            std::cout << "div:     "<< students[i].division << std::endl;
            std::cout << "year:     "<< students[i].year << std::endl;
            found = true;
            break;
        }
        
    }
    
    if (!found)
    {
       std::cout<< endl << "Student not found " << std::endl;
    }
    

    return 0;
}
