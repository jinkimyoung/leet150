
// Bit Manipulation
// Time complexity: O(32n)
// Space complexity: O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<32;i++){
            int s=0;
            for(auto it:nums)
                s+=it>>i&1;
            s%=3;
            ans|=s<<i;
        }
        return ans;
    }
};

class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int ones = 0;
    int twos = 0;

    for (const int num : nums) {
        ones ^= (num & ~twos);
        twos ^= (num & ~ones);
    }

    return ones;
  }
};