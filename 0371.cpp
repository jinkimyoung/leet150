

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        unsigned int carry;
        
        while (b != 0)
        {
            // type casting 중요함
            carry = ((unsigned int)(a & b)) << 1;
            a = a ^ b;
            b = (int)carry;
        }
        return a;
    }
};