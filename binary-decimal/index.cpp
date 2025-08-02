#include <iostream>
#include <math.h>   



//binary to decimal
// int main(int argc, char const *argv[])
// {
//     int number =101100110;
//     int sum =0 ;
//     int index = 0;
//     while (number>0)
//     {
//         int value = number % 10;
//         sum += (value << index);            //it multiplies by index number in mutilpe of 2 in value such index = 2 , 2 X 2
//         index++;
//         number /= 10 ;
        
//     }
    
//     std::cout << "number "<< sum << std::endl;

//     return 0;
// }


// int main(int argc, char const *argv[])
// {
//     int number = 1010;
//     int arr[4];
//     for (int index  = 0; index  < 4; index ++)
//     {
//         int value = number % 10 ;
//         arr[ 3 - index ] = value * (pow(2, index));
//         number /= 10 ;

//     }
//     std::cout << "\n" << std::endl;

//     int ans = 0;
//     for (int i = 0; i < 4; i++)
//     {
//         ans += arr[i];
        
//     }
//     std::cout << ans ;
    
//     return 0;
// } 
