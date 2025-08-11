//searching using pivot element 
//

#include<iostream>
#include<vector>
using namespace std;

int PivotTarget(vector<int>&arr, int size ){
    int start = 0,  end = size -1;
    int mid = start +(end - start )/2 ;

    while (start < end)
    {
        if (arr[mid] >= arr[0])
            start = mid + 1;
         else  
            end = mid ;

        mid = start +(end - start )/2 ;
    }
   return start;  // pivot
   
}

int binarySeach(vector<int> &arr, int start, int end, int key){
    
    int mid = start + (end - start)/2;   //this of int range error if start +end > range(int)=> error                             //(start +end )/2;

    while (start <= end )
    {
        if (arr[mid] == key)  return mid ;
            
        if (key > arr[mid]) 
            start = mid + 1;

        else 
            end = mid -1;

        mid =  start + (end - start)/2;
    }
    return -1 ; 

}

int Target(vector<int>&arr, int target){
    int size = arr.size();
    int pivot = PivotTarget(arr, size);

    if (target >= arr[pivot] && target <= arr[size -1])
        return binarySeach(arr, pivot , size-1 ,target);

    else
         return binarySeach(arr, 0 ,pivot-1, target);    
  
}

int main()
{
    vector<int> arr = {7,9,13,15,1,2,3};
    int target = 2;
    int index = Target(arr, target);

    if (index != -1)
        cout << "Target found at index " << index << endl;
    else
        cout << "Target not found" << endl;

    return 0;
}
