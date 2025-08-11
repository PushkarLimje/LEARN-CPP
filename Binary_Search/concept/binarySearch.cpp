#include<iostream>
using namespace std;

int binarySeach(int arr[], int size , int key){
    int start = 0;
    int end = size - 1;

    int mid = start + (end - start)/2;   //this of int range error if start +end > range(int)=> error                             //(start +end )/2;

    while (start <= end )
    {
        if (arr[mid] == key)
        {
            return mid ;
            
        }

        if (key > arr[mid])
        {
            start = mid + 1;

        }else {
            end = mid -1;
        }
        // mid = (start +end )/2;

        mid =  start + (end - start)/2;
    }
    return -1 ; 

}

int main()
{
    int arr1[6] = {2,4,6,9,15,29};
    int arr2[5] = {3,5,6,18,27};

    int ans = binarySeach(arr1, 6 , 29);
    std::cout << "Index: "<< ans << std::endl;
    return 0;
}

