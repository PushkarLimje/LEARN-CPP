#include<iostream>
#include<vector>

using namespace std;

void bubbleSort( vector<int> &arr ){

    int n = arr.size();
    for (int i = 0; i < n -1; i++)
    {
        bool isSwapped = false ;
        for (int j = 0; j < (n-i-1); j++)
        {
            if (arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                isSwapped =true;
            }
            
        }

        if (!isSwapped)
        {
            break;
        }
        
    }
    
}

int main()
{
    vector<int> arr = { 41,2,65,9,85,17,4};
    bubbleSort(arr);
    std::cout << "sorted array: " << std::endl;
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}