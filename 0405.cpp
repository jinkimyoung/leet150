// Time : O(N), Space : O(16)

#include <string>
using namespace std;

class Solution {
public:
    string toHex(int num) {
        unsigned int target = num;
        string ref = "0123456789abcdef";
        string out;

        do
        {
            int idx = target % 16;
            target = target >> 0x4;
            out = ref[idx] + out;
        } while (target > 0);

        return out;
    }
};