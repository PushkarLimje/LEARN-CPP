#include<iostream>
#include<vector>
using namespace std;
//IntroSort
int main(int argc, char const *argv[])
{
    vector<int> v ;
            //sizeof = 5 , number in each box = 1 
    vector<int> a(5,1);
    vector<int> last(a);

    for(int i : last){ 
        std::cout << last[i] << "  " ;
    }


    std::cout << "\nCapacity : "<< v.capacity() << std::endl;
    // every time double the capacity of the array when there is no space

    v.push_back(1);     // adding 1 from back
    std::cout << "Capacity : "<< v.capacity() << std::endl;
    v.push_back(2);     // adding 2 from back
    std::cout << "Capacity : "<< v.capacity() << std::endl;
    v.push_back(3);     // adding 3 from back
    std::cout << "Capacity : "<< v.capacity() << std::endl;
    v.push_back(5);     // adding 4 from back
    std::cout << "Capacity : "<< v.capacity() << std::endl;
    std::cout << "Capacity : "<< v.capacity() << std::endl;
    v.push_back(6);     // adding 4 from back
    std::cout << "Capacity : "<< v.capacity() << std::endl;
    v.pop_back();     // removes 4 from back
    std::cout << "Capacity : "<< v.capacity() << std::endl;

    //most of them are same as array STL; at, front, back

    v.clear();      // clear the array (size = 0) but capacity remains the same 
                    // capacity = memory allocated to an array

    for(int i : v){ // cleared the array
        std::cout << v[i] << "  " << std::endl;
    }
    
    return 0;
}
