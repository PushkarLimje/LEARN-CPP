#include<iostream>
#include<math.h>

using namespace std;

bool isPowerOfTwo(int n){
  
   for (int i = 0; pow(2 , i) <= n; i++)
   {
        int power = pow(2, i);
        if (power == n)
        {
            return true ;
        } 
                
   }
   return false ;
   
}

int main()
{
    
    std::cout << "is Power of 2 : "<< isPowerOfTwo(1) << std::endl;
    return 0;
}
