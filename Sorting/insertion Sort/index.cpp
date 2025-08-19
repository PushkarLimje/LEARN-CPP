#include<iostream>
#include <vector>
using namespace std;

void insertion(vector<int> & arr){
    for (int i = 0; i < arr.size(); i++)
    { 
        int temp = arr[i];
        int j = i - 1;
        for ( ;j >= 0 ; j-- )
        {
            if (arr[j] > temp)
                //shift
                arr[j+1] = arr[j];
            else
                break;
            
        }
        arr[j+1] = temp ;
    }
}    


void insertionSort(vector<int> & arr){
    for (int i = 1; i < arr.size(); i++)
    { 
        int temp = arr[i];
        int j = i - 1;
        while ( j >= 0 )
        {
            if (arr[j] > temp)
                //shift
                arr[j+1] = arr[j];
            else
                break;
           
            j--;
        }
        arr[j+1] = temp ;
        
    }
    
}

int main()
{
    vector<int> arr = {15,14,13,12,11};
    insertionSort(arr);
    // insertion(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i]<< ",   ";
    }
    
    return 0;
}
