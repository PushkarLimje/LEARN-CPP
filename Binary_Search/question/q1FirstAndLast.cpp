#include <iostream>
#include <vector>
using namespace std;

int firstOcc(int arr[], int n , int key){
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start )/2;
    int ans = -1;

    while (start <= end)
    {
        if (arr[mid] == key)
        {
            ans = mid ;
            end = mid - 1;

        }

        if (key > arr[mid])
        {
            start = mid + 1 ;

        } else if (key < arr[mid]){
            end = mid - 1 ;
        }
        mid = start + (end - start )/2 ;
        
    }
    return ans;
}

int LastOcc(int arr[], int n , int key){
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start )/2;
    int ans = -1;

    while (start <= end)
    {
        if (arr[mid] == key)
        {
            ans = mid ;
            start = mid + 1;

        }

        if (key > arr[mid])
        {
            start = mid + 1 ;

        } else if (key < arr[mid]){
            end = mid - 1 ;
        }
        mid = start + (end - start )/2 ;
        
    }
    return ans;
}

int TotalOcc(int arr[], int size ){
    int first =  firstOcc(arr ,10 , 5);
    int last =  LastOcc(arr ,10 , 5);
    int count = last - first + 1;
    return count ;
}
int main()
{
    int arr1[10] = {1,1,1,2,2,5,5,5,5,5};
    cout<< "First occurence :  " << firstOcc(arr1 , 10, 5)<< endl;
    cout<< "last occurence : " << LastOcc(arr1 , 10, 5)<< endl;
    cout<< "total occurence : " << TotalOcc(arr1 , 10)<< endl;


    return 0;
}

