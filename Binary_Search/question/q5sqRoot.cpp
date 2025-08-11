#include <iostream>
#include <vector>
using namespace std;

int binarySearch(int n){
    int start = 0;
    int end = n ;
    int mid = start + (end - start )/2;

    int ans = -1;

    while (start <= end )
    {
        int square = mid * mid ;
        if (square == n )
        {
            return mid;
        }
        if (square > n )
            end = mid -1;

        else
        {
            ans = mid ;
            start = mid +1 ;
        }
        mid = start + (end - start )/2;     
    }
    return ans;
}



int main()
{
    int n = 55;
    std::cout << "square root : "<< binarySearch(n) << std::endl;
    std::cout << "hello" << std::endl;
    return 0;
}


// int sqRoot(vector<int>&arr ,int number ){
//     int start = 0;
//     int end = arr.size()-1;
//     int mid =  start +(end - start)/2;
//     int ans = 0;
//     while (start <= end ){
//         if ((arr[mid]*arr[mid]) == number)
//             return arr[mid] ;        
//         if ((arr[mid]*arr[mid]) > number)
//             end = mid - 1 ;
//         else{
//             ans = arr[mid];
//             start = mid + 1;
//         }
//         mid =  start +(end - start)/2; 
//     }
//     return ans;
// }
// int main() {
//     int number  = 193 ;
//     vector<int> arr;
//     for (int i = 0; i < number; i++)
//     {
//         arr.push_back(i);
//     }
//     std::cout << "square root : "<< sqRoot(arr, number) << std::endl;  
//     return 0;
// }