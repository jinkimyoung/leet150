#include <algorithm>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0)
            x = 1/x;
        
        int num = abs(n);
        double pow = 1;
        
        while (num)
        {
            if (num & 0x1)
                pow = pow * x;
            x = x * x;
            num = num >> 0x1;
        }
        return pow;
    }
};
