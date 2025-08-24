#include <iostream>
#include <vector>
using namespace std;

//Print Array 
void printArray(vector<int> &arr) {
    for (int x : arr) cout << x << " ";
    cout << endl;
}

//Quick Sort
int partition(vector<int> &arr, int low, int high, int &pass) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);

    cout << "Pass " << pass++ << ": ";
    printArray(arr);

    return i + 1;
}

void quickSort(vector<int> &arr, int low, int high, int &pass) {
    if (low < high) {
        int pi = partition(arr, low, high, pass);
        quickSort(arr, low, pi - 1, pass);
        quickSort(arr, pi + 1, high, pass);
    }
}

// Divide and Conquer for Min & Max
pair<int, int> findMinMax(vector<int> &arr, int low, int high) {
    if (low == high) {
        return {arr[low], arr[low]};  // one element
    }
    if (high == low + 1) {
        if (arr[low] < arr[high])
            return {arr[low], arr[high]};
        else
            return {arr[high], arr[low]};
    }

    int mid = (low + high) / 2;
    pair<int, int> left = findMinMax(arr, low, mid);
    pair<int, int> right = findMinMax(arr, mid + 1, high);

    int finalMin = min(left.first, right.first);
    int finalMax = max(left.second, right.second);

    return {finalMin, finalMax};
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    vector<int> marks(n);
    cout << "Enter marks of " << n << " students:\n";
    for (int i = 0; i < n; i++) cin >> marks[i];

    cout << "\nOriginal Marks: ";
    printArray(marks);

    int pass = 1;
    quickSort(marks, 0, n - 1, pass);

    cout << "\nSorted Marks: ";
    printArray(marks);

    pair<int, int> result = findMinMax(marks, 0, n - 1);
    cout << "\nMinimum Marks = " << result.first << endl;
    cout << "Maximum Marks = " << result.second << endl;

    return 0;
}
