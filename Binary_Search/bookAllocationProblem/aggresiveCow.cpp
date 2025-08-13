#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

bool isPossibe(vector<int>&arr,int k , int mid ){
    int cowCount = 1;
    int lastPosition = arr[0];
    
    for (int i = 0; i < arr.size() ; i++)
    {
        if ((arr[i] - lastPosition) >= mid)
        {
            cowCount++;
            if (cowCount == k) return true;    
            
            lastPosition = arr[i];
        }
        
    }
    return false;
}

int binarySerach(vector<int>&arr, int k ){
    sort(arr.begin(), arr.end());
    int start = 0;
    int maxi = -1;

    for (int i = 0; i < arr.size(); i++)
    {
        maxi = max(maxi, arr[i]);
    }

    int end = maxi;
    int ans = -1 ;
    while (start <= end )
    {
        int mid = start + (end - start)/2;

        if (isPossibe(arr, k, mid)){   
            ans = mid ;
            start = mid + 1;
        } else {
            end = mid -1;
        }
        
    }
    
    return ans;
}

int main() {
    int k = 2;
    vector<int > arr = {100,99,1,333,0};
    int n = arr.size();

    std::cout << "maximum distance :  "<< binarySerach(arr,k) << std::endl;
    return 0;
}