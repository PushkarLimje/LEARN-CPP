#include <iostream>
#include <vector>
using namespace std;

struct Employee {
    string name;
    float height;
    float weight;
    float average;
};

// Print Employees 
void printEmployees(vector<Employee> &arr) {
    cout << "\nName\tHeight\tWeight\tAverage\n";
    for (auto &e : arr) {
        cout << e.name << "\t" << e.height << "\t" << e.weight << "\t" << e.average << endl;
    }
}

//Selection Sort
void selectionSort(vector<Employee> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].average < arr[minIdx].average) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

// Merge Sort
void merge(vector<Employee> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;

    vector<Employee> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].average <= R[j].average) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<Employee> &arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    cout << "Enter number of employees: ";
    cin >> n;

    vector<Employee> employees(n), employeesCopy(n);

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details of employee " << i + 1 << ":\n";
        cout << "Name: ";
        cin >> employees[i].name;
        cout << "Height: ";
        cin >> employees[i].height;
        cout << "Weight: ";
        cin >> employees[i].weight;
        employees[i].average = (employees[i].height + employees[i].weight) / 2.0;
    }

    // Copy for merge sort
    employeesCopy = employees;

    // Selection Sort
    selectionSort(employees);
    cout << "\n--- Employees Sorted by Selection Sort ---";
    printEmployees(employees);

    // Merge Sort
    mergeSort(employeesCopy, 0, n - 1);
    cout << "\n--- Employees Sorted by Merge Sort ---";
    printEmployees(employeesCopy);

    // Complexity Analysis
    cout << "\nTime Complexity Analysis:\n";
    cout << "Selection Sort: O(n^2)\n";
    cout << "Merge Sort: O(n log n)\n";
    

    return 0;
}
