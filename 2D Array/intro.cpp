#include <iostream>
using namespace std ;

int main()
{
    int arr[2][2];
    std::cout << "Enter the number in array" << std::endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin>>arr[i][j];
        }
        
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl<<endl;
    }
    
    return 0;
}
