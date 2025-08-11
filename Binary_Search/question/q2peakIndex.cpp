#include <iostream>
#include <vector>

using namespace std;

//linear search

// int peak (int arr[], int size ){
//     int ans ;
//     int index;
//     for (int i = 0; arr[i] <= arr[i+1] ; i++)
//     {
//         ans = arr[i+1];
//         int ele =i+1 ;
//         index = ele ;
//     }
//     return index ;
// }


// Binary search ;

int peak(int arr[], int size){
    int start = 0;
    int end = size - 1;
    int mid = start +(end - start)/2;

    while (start < end)
    {
        if (arr[mid] < arr[mid+1])
        {
            start = mid +1 ;
        }else {
            end = mid ;
        }
        mid = start +(end - start)/2;
    }
    return start;
}

int main()
{
    int arr[6] = {1,4,2,2,3,1};
    std::cout << "index :  " << peak(arr, 6)<< std::endl;
    // std::cout << "answer :  " << peak(arr, 6)<< std::endl;
    return 0;
}

