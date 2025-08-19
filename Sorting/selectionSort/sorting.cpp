#include<iostream>
#include<vector>

using namespace std;

void selectionSort(vector<int> &arr){

    int n = arr.size();
    for (int i = 0; i < n-1; i++)
    {
        int minIndex = i;

        for (int j = i+1 ; j < n; j++)
        {   
            if (arr[minIndex] > arr[j])
                minIndex = j;
                           
        }
        swap(arr[minIndex],arr[i]);
    }
    
}

int main()
{
    vector<int> arr = { 41,2,65,9,85,17,4};
    selectionSort(arr);
    std::cout << "sorted array: " << std::endl;
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
