#include <iostream>
using namespace std;

// in function we send address of that array not copy ;

int max(int arr[], int a){
    int max = INT8_MIN;             // INT8_MIN means pow (2,-31)
    for (int i = 0; i < 5; i++)
    {
        if (arr[i] > max)            // comparing if arr[i] > max then change max value to arr[i];
        {
            max= arr[i];
        }
        
    }
    return max;
};
int min(int arr[], int a){
    int mini = INT8_MAX;                 //INT8_MAX means [pow(2,31)-1]
    for (int i = 0; i < a; i++)
    {

        mini = min( mini, arr[i] );            // same logic of below if statement 

        // if (arr[i] < mini)               // comparing if arr[i] < min then change max value to arr[i];
        // {
        //     min= arr[i];
        // }
        
     return mini;
    }
}

int main()
{
    int a = 5 ;
    int arr[a];

    // input value 
    for (int i = 0; i < 5; i++)
    {
        std::cout << "enter the " << i+1 <<"th number" << std::endl;
        cin>>arr[i];
    }
    
    cout << "Maximum value is: " << max(arr, a) << endl;
    cout << "Minimum value is: " << min(arr, a) << endl;
    
    return 0;
}

