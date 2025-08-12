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


//more precision in answer .
double morePrecision(int n , int precision , int root){
    double ans = root;
    double factor = 1;
    for (int i = 0; i < precision; i++)
    {
        factor /=  10;

        for (double j = ans; j*j < n ; j+= factor){
            ans = j;
        }
        
    }
    return ans ;
}

int main()
{
    
    int n ;
    std::cout << "Enter the number" << std::endl;
    cin>> n ;
    int decimal ;
    std::cout << "Enter the precision " << std::endl;
    cin>> decimal ;

    int root = binarySearch(n);
    std::cout << "square root : "<< binarySearch(n) << std::endl;
    std::cout << "precise answer:   "<< morePrecision(n, decimal, root) << std::endl;
    
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