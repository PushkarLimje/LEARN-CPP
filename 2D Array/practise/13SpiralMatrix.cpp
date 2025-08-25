#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralPath(vector<vector<int>>& arr ){
    int rowSize = arr.size();
    int colSize = arr[0].size();

    int firstCol = 0, lastCol = colSize - 1 ;
    int firstRow = 0, lastRow = rowSize - 1 ;

    int count = 0;
    int total = colSize * rowSize ;
    vector<int> ans ;

    while (count < total)
    {
        // Traverse top row
        for (int col = firstCol; count < total && col <= lastCol ; col++){
            //std::cout << arr[firstRow][col] <<  "  " ; 
            ans.push_back(arr[firstRow][col]);
            count++;
        }
        firstRow++;

        // Traverse right column
        
            for (int row = firstRow;count < total && row <= lastRow; row++)
                {
                    //std::cout <<arr[row][lastCol] << "  " ;  
                    ans.push_back(arr[row][lastCol]) ;   
                    count++;      
                }
                lastCol--;

        // Traverse bottom row (if still valid
            for (int col = lastCol;count < total && col >= firstCol; col--)
                {
                    //std::cout <<arr[lastRow][col] << "  " ;
                    ans.push_back(arr[lastRow][col]);
                    count++;
                }
                lastRow--;
        
            for (int row = lastRow;count < total && row >= firstRow; row--)
                {
                    //std::cout <<arr[row][firstCol] << "  ";
                    ans.push_back(arr[row][firstCol]);
                    count++;
                }
                firstCol++;            
                
    }
    
    return ans;
}

int main()
{
    int n,m ;
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
    vector<int> result = spiralPath(arr);

    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << "  " ;
    }
    
    return 0;
}