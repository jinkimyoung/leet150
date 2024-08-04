

#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    int myAtoi(string s) 
    {
        int m = s.length(), i = 0;
        int r = 0, d = 0, sign = 1;

        while (i < m && s[i] == ' ')
            i++;
        
        if (i < m && s[i] == '+')
        {
            i++;        
            sign = 1;
        }
        else if (i < m && s[i] == '-')
        {
            i++;        
            sign = -1;
        }

        while (i < m && s[i] >= '0' && s[i] <= '9')
        {
            d = s[i] - '0';
            i++;
            if (r > (INT_MAX/10) || r == (INT_MAX/10) && d > (INT_MAX%10))
                return sign > 0 ? INT_MAX : INT_MIN;
            r = r * 10 + d;
        }
        return sign * r;
    }
};

