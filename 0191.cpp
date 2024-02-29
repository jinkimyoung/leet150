
typedef unsigned int uint32_t;
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while (n)
        {
            if (n & 0x1)    ans++;
            n = n >> 0x1;
        }
        return ans;
    }
};