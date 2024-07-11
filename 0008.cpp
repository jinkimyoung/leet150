

#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    int myAtoi(string s) 
    {
        int ans = 0, i = 0, minus = 0, m = s.length();

        while (i < m && s[i] == ' ')
            i++;

        if (i < m && s[i] == '+')
        {
            minus = 0;
            i++;
        }
        else if (s[i] == '-')
        {
            minus = 1;
            i++;
        }

        while (s[i] >= '0' && s[i] <= '9' && i < m)
        {
            if ((ans > INT_MAX / 10) || (ans == INT_MAX / 10 && (s[i]-'0') > INT_MAX % 10))
            {
                return (minus == 1 ? INT_MIN : INT_MAX);
            }
            ans = ans * 10 + (s[i] - '0');
            i++;
        }
        return minus == 1 ? -1 * ans : ans;  
    }
};