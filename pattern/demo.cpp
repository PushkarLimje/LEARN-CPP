#include <iostream>
using namespace std;

int main()
{
    int n;
    std::cout << "enter the n " << std::endl;
    cin>>n;

    for (int row = 0; row <=n ; row++)
    {
        for (int col = n -row ; col>0 ; col--)
        {
            std::cout << "*";

        }
        
        std::cout  << std::endl;
    }


    return 0;
}

// int main()
// {
//     int n;
//     std::cout << "enter the n " << std::endl;
//     cin>>n;

//     //_ _ _ *
//     //_ _ * * 
//     //_ * * * 
//     //* * * *

//     for (int  row = 1; row <= n; row++)
//     {
//         //space printing
        
//         for (int space =  n - row ; space ; space--)
//         {
//             std::cout << " " ;
//         }
        
//         //star printing
//         for (int col = 1; col <= row; col++)
//         {
//             std::cout << "*";
//             // different by adding space 
//         } 
//         std::cout << std::endl;
//     }
    

//     return 0;
// }

// int main()
// {
//     int n;
//     std::cout << "enter the n " << std::endl;
//     cin>>n;
//     // ABC
//     // BCD
//     // CDE
//     // for (int row = 0; row < n; row++)
//     // {
//     //     for (int col = 0; col < n; col++)
//     //     {
//     //         char value = 'A'+row+col;
//     //         std::cout <<  value;
//     //     }
//     //     cout<<endl;
//     // }
//     // ABC
//     // BCD
//     // CDE
//     // for (int i = 1; i <= n; i++)
//     // {
//     //     int value = i;
//     //     char st = 'A'+i -1 ;
//     //     for (int j = 1; j <= n; j++)
//     //     {
//     //         std::cout << st ;
//     //         st++;
//     //     }
//     //     cout<<endl;
//     // }    
//     return 0;
// }

//ABC
//DEF
//GHI
// int main()
// {
//     int n;
//     std::cout << "enter the n " << std::endl;
//     cin>>n;
//     char value = 'A';
//     for (int row = 1; row <= n; row++)
//     {       
//         for (int col = 1; col <= n; col++)
//         {     
//            std::cout << value ;
//            value++;
//         }
//         cout<<endl;
//     }
//     return 0;
// }

// letter print
// int main()
// {
//     int n;
//     std::cout << "enter the n " << std::endl;
//     cin>>n;   
//     for (int row = 1; row <= n; row++)
//     {       
//         for (int col = 1; col <= n; col++)
//         {     
//             char value = 'A' + col -1  ;
//            std::cout << value ;
//         }
//         cout<<endl;
//     }
//     return 0;
// }

//pattern reverse no.st tri
// int main() {
//     int n;
//     std::cout << "enter the n " << std::endl;
//     cin>>n;
//     for (int i = 1; i <= n; i++)
//     {   
//         int temp = i;
//         for (int j = 1; j <= i; j++)
//         {
//             // std::cout << temp ;
//             //     temp--;         
//             std::cout << (i-j)+1 ;
//         }
//         std::cout  << std::endl;
//     }   
//     return 0;
// }

// pattern 
// int main() {
//     int n;
//     std::cout << "enter the n " << std::endl;
//     cin>>n;
//     for (int i = 1; i <= n; i++)
//     {
//         int temp = i;
//         for (int j = 1; j <= i; j++)
//         {           
//             std::cout << temp<<" " ;
//             temp++;
//         }
//         std::cout << std::endl;
//     }   
//     return 0;
// }
