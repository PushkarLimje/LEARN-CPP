#include <iostream>
#include <cstdlib> 
using namespace std;



int main()
{
    int n;
    cout<< "enter the value of n " ;
    cin >> n ;
    int arr[n][n];
    std::cout << "enter the number of N x N " << std::endl;


    //input
    for (int  i = 0; i < n ; i++)
    {
        for (int j = 0;j < n; j++)
        {
           
           
            arr[i][j] = rand();
        }
        
    }
    std::cout << "" << std::endl<< endl;


    //output
    for (int  i = 0; i < n ; i++)
    {
        for (int j = 0;j < n; j++)
        {
            std::cout << arr[i][j] <<"\t";
        }
        cout<<endl;
    }
    
    
    int sum[3] = {0};
    for (int  i = 0; i < n ; i++)
    {   

        for (int j = 0;j < n; j++)
        {
            sum[i] += arr[i][j];
            std::cout << arr[i][j] <<"\t";
        }
        cout<<endl;
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << "sum "<< i+1 << "    "<< sum[i] << std::endl;
    }
    
    return 0;
}