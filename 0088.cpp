
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int dst = (m+n-1), i=m-1, j=n-1;

        while (i >= 0 && j >= 0)
        {
            if (nums1[i] <= nums2[j])
                nums1[dst--] = nums2[j--];
            else
                nums1[dst--] = nums1[i--];
        }

        while (i >= 0)            
            nums1[dst--] = nums1[i--];

        while (j >= 0)            
            nums1[dst--] = nums2[j--];            
    }
};