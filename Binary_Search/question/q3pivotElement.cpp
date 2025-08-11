// find the pivot element of the array 
//where the continuty breaks 

#include<iostream>
using namespace std;

int pivotElement(int arr[], int size ){
    int start = 0;
    int end = size -1 ;
    int mid = start + (end - start)/2;
    
    while (start < end )
    {
        if (arr[mid] >= arr[0])            // until the element is greater than 0 th element 
        {
            start = mid + 1 ;

        } else {
            end = mid ;                 // (mid - 1) changes direction or line in the graph
        }
       mid = start + (end - start)/2; 
    }
    return start ;
}

int main(int argc, char const *argv[])
{
    int arr[6] = {4,6,7,9,0,1};

    std::cout << "Pivot element : " << pivotElement(arr , 6)<< std::endl;

    return 0;
}
