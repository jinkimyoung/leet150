#include <iostream>
using namespace std;

//  Function to check if x is power of 2
bool isPowerOfTwo(int x)
{
     // First x in the below expression is
     // for  the case when x is 0 
     return x && (!(x & (x - 1)));
}

 static int toggleBit(int number, int index) {
    int mask = 1 << index;
    return number ^ mask;
}


int main(void)
{
    for (int i = 0; i <= 16; i++)
        std::cout << i << " : " << isPowerOfTwo(i) << endl;          
  
}