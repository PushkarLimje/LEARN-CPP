//question 240 
//Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

// Integers in each row are sorted in ascending from left to right.
// Integers in each column are sorted in ascending from top to bottom.

// Input: matrix = [
                //     [1,4,7,11,15],
                //     [2,5,8,12,19],
                //     [3,6,9,16,22],
                //     [10,13,14,17,24],
                //     [18,21,23,26,30]
                // ], 
                // target = 5
// Output: true
//2 pointer approch 

#include <iostream>
#include<vector>
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rowSize = matrix.size();
    int colSize = matrix[0].size();
    int rowIndex = 0 ;
    int colIndex = colSize - 1;

    while (rowIndex< rowSize && colIndex >= 0)
    {
        int element = matrix[rowIndex][colIndex];
        if (element == target)
        {
            return true ;
        }
        if (element < target )
        {
            rowIndex++;     // move downwards 
        }
        else
        {
            colIndex--;     // move left
        }
                
    }
    return 0;
}
int main()
{
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    int target = 14;
    if (searchMatrix(matrix, target)) {
        cout << "Found " << target << endl;
    } else {
        cout << "Not Found" << endl;
    }

    return 0;
}