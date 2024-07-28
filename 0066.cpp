


#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int one = 1;
        int i = 0;
        reverse(digits.begin(), digits.end());

        while (one != 0) {
            if (i < digits.size()) {
                if (digits[i] == 9) {
                    digits[i] = 0;
                } else {
                    digits[i]++;
                    one = 0;
                }
            } else {
                digits.push_back(one);
                one = 0;
            }
            i++;
        }
        reverse(digits.begin(), digits.end());
        return digits;
    }
};



class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        int one = 1, i = 0, n = digits.size();

        while (one && i < n)
        {
            if (digits[i] == 9)
                digits[i] = 0;
            else
            {
                digits[i]++;
                one = 0;                    
            }
            i++;
        }
        if (one)
            digits.push_back(1);

        reverse(digits.begin(), digits.end());        
        return digits;
    }
};

