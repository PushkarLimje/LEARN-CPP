#include <iostream>
#include<array>
using namespace std;

int main(int argc, char const *argv[])
{
    int basic[4] = {1,2,3,4};
    array<int,4> a = {4,3,2,1};

    for (int i = 0; i < a.size(); i++)
    {
        std::cout << a[i] << "  " << std::endl;
    }
    std::cout << "at index 3 "<< a.at(3)<< std::endl;
    std::cout << "at front  "<< a.front()<< std::endl;
    std::cout << "at back  "<< a.back()<< std::endl;

    return 0;
}

// same as basic array