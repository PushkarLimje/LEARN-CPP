#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student {
    string name;
    int prevMarks;
    int rollNo; 
};

void printPass(const vector<Student>& a, int passNo, int swapsThisPass) {
    cout << "Pass " << passNo << " (swaps: " << swapsThisPass << "): ";
    for (const auto& s : a) {
        cout << "[" << s.name << ":" << s.prevMarks << "] ";
    }
    cout << "\n";
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    vector<Student> a(n);
    for (int i = 0; i < n; i++) {
        cout << "\nEnter name of student " << i+1 << ": ";
        cin >> a[i].name;
        cout << "Enter previous-year marks of " << a[i].name << ": ";
        cin >> a[i].prevMarks;
        a[i].rollNo = 0;
    }

    cout << "\nOriginal order: ";
    for (auto &s : a) cout << "[" << s.name << ":" << s.prevMarks << "] ";
    cout << "\n\n--- Bubble Sort (descending by marks) ---\n";

    int passNo = 0;
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        int swapsThisPass = 0;
        for (int j = 0; j < n - i - 1; j++) {
            
            if (a[j].prevMarks < a[j+1].prevMarks) {
                swap(a[j], a[j+1]);
                swapped = true;
                swapsThisPass++;
            }
        }
        passNo++;
        printPass(a, passNo, swapsThisPass);
        if (!swapped) break;
    }

    for (int i = 0; i < n; i++) {
        a[i].rollNo = i + 1;
    }

    cout << "\n--- Final Roll List (after sorting) ---\n";
    cout << "Roll\tName\tMarks\n";
    for (const auto& s : a) {
        cout << s.rollNo << "\t" << s.name << "\t" << s.prevMarks << "\n";
    }

    return 0;
}
