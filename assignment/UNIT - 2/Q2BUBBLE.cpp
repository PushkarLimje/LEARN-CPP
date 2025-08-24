// WAP to implement Bubble sort and Quick Sort on a 1D array of Student structure (contains student_name, student_roll_no, total_marks), with key as student_roll_no. And count the number of swap performed by each method.

#include <iostream>
#include<string>
using namespace std;

struct Student
{
    string name;
    int rollNumber;
    int totalMarks;
};

int bubbleSort(Student arr[], int n){
    
    int count = 0;
    for (int i = 0; i < n-1; i++)
    {
        bool isSwapped = false ;
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j].rollNumber > arr[j+1].rollNumber)
                {
                    swap(arr[j] , arr[j+1]);
                    count++ ;
                    isSwapped =true ;
                }
        }
        if (!isSwapped)
        {
            break;
        }
        
    }
    return count;
}

int quickSortSwapCount = 0;

int partition(Student arr[], int low, int high) {
    int pivot = arr[high].rollNumber;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j].rollNumber < pivot) {
            i++;
            swap(arr[i], arr[j]);
            quickSortSwapCount++;
        }
    }
    swap(arr[i + 1], arr[high]);
    quickSortSwapCount++;
    return (i + 1);
}

void quickSort(Student arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printStudents(Student arr[], int n) {
    cout << "\nRollNo\tName\tMarks\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i].rollNumber << "\t" << arr[i].name << "\t" << arr[i].totalMarks << endl;
    }
}

int main()
{
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student students[n], studentsCopy[n];

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details of student " << i+1 << ":\n";

        cout << "Name :  ";
        cin >> students[i].name;
        cout << "Roll No: ";
        cin >> students[i].rollNumber;
        cout << "Marks : ";
        cin >> students[i].totalMarks;
    } 
    
    for (int i = 0; i < n; i++) studentsCopy[i] = students[i];
    //bubble sort 
    std::cout << "number of swap : "<< bubbleSort(students, n) << std::endl;

    //quick sort 
    quickSort(studentsCopy, 0, n - 1);
    cout << "\n--- After Quick Sort ---\n";
    printStudents(studentsCopy, n);
    cout << "Number of swaps in Quick Sort: " << quickSortSwapCount << endl;
    return 0;
}