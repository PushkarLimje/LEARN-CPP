#include <iostream>
#include <vector>
using namespace std;

vector<int> binarySearch(vector<vector<int>>& arr,int  target){
    int rowSize = arr.size();
    int colSize = arr[0].size();
    int start = 0;
    int end = rowSize * colSize - 1;
    
    while (start <= end )
    {
        int mid  = start + (end - start )/2 ;
        int element = arr[mid / colSize][mid % colSize];
                      // row = index       col= index
        if (element == target)
        {
           
            return {mid / colSize, mid % colSize};
            // return true ;
        }
        if (element < target)
        {
            start = mid + 1;
        } else {
            end = mid - 1 ;
        }        
        
    }
    return {-1, -1};
    // return false;
}

int main()
{
    int n,m , target = 5;
    std::cout << "enter the dimension of the matrix" << std::endl;
    cin>> n>> m;
    vector<vector<int>> arr(n, vector<int>(m));
    int number = 1  ;

    //input
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = number;
            number++;
        }
        std::cout << "" << std::endl;
    }

    //output
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << arr[i][j]<<"  " ;
        }
        std::cout << "" << std::endl;
    }

    std::cout << "" << std::endl;

     vector<int> result = binarySearch(arr, target);

    if (result[0] != -1) {
        cout << "Target found at position: (" << result[0] << ", " << result[1] << ")" << endl;
    } else {
        cout << "Target not found" << endl;
    }
    
    
    return 0;
}