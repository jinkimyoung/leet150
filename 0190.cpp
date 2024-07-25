
typedef unsigned int uint32_t;
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;

        for (int i = 0; i < 32; i++)
        {
            ans = ans << 0x1;
            if (n & 0x1)
                ans = ans | 0x1;
            n = n >> 0x1;
        }
        return ans;
    }
};