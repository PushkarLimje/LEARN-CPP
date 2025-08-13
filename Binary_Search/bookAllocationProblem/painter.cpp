// minimum time to paint the number of block in 2 painter 

#include<iostream>
#include<vector>
using namespace std;
bool isPossible(vector<int>&arr , int m , int n, int mid ){
    
    int painter = 1 ;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
       
        if ((sum + arr[i]) <= mid )
        {
            sum += arr[i];
        } else {
            painter ++;
            if (painter > m || arr[i] > mid )
            {
                return false;
            }
            sum = arr[i];
        }                
    }    
    return true ;
}

int binarySearch(vector<int>&arr , int m , int n){
    int start = 0;
    int sum =0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i] ;
    }

    int end = sum ;
    int ans = -1 ;
    while (start <= end)
    {
        int mid = start + (end - start)/2 ;

        if (isPossible( arr, m, n, mid )){
            ans = mid;
            end = mid - 1;
        } else {
            start = mid +1 ;
        }
        
    }
    return ans;
}

int main()
{
    int m = 3;

    vector<int> arr = {5,6,7,8,9};
    int n = arr.size();
    std::cout << "minimum :  "<< binarySearch(arr, m , n) << std::endl;
    return 0;
}
