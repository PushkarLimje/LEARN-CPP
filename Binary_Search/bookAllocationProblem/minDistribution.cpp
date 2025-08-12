#include <iostream>
#include<vector>
using namespace std;

bool isPossible(vector<int>& arr, int n , int m, int mid){
   int studentCount = 1;
   int pageSum = 0;

   for (int i = 0; i < n; i++)
   {
        if ( pageSum + arr[i] <= mid )
            pageSum += arr[i];
        
        else {  
            studentCount++;
            if (studentCount > m || arr[i] > mid ){
                return false;
            }
            pageSum = arr[i];
        }      
        
   }
   return true;
}

int binarySearch(vector<int>& arr, int n , int m){
    int start = 0;
    int sum = 0 ;

    for (int i = 0; i < n ; i++)
        sum += arr[i];
    
    int end = sum;
    int ans = -1;

    while (start <= end )
    {
        int mid = start + (end - start)/2;
        if (isPossible(arr, n, m,  mid)){
            ans = mid ;
            end = mid - 1; 
        }
        else {
            start = mid + 1;
        }
        
    }
    return ans ;
}


int main()
{
    int n = 4, m = 2;
    
    vector<int> arr = {12,37,96,108};
    
    std::cout << "answer :" << binarySearch(arr, n , m)<< std::endl;
    return 0;
}
