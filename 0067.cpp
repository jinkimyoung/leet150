


#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length() - 1, j = b.length() - 1;
        int sum = 0, carry = 0;
        string s;
        while (i >= 0 || j >= 0)
        {
            int v1 = (i >= 0 ? a[i]-'0' : 0);
            int v2 = (j >= 0 ? b[j]-'0' : 0);          

            sum = (v1 + v2) + carry;
            carry = sum / 2;
            s += ('0'+(sum%2));
            i--;
            j--;
        }
        if (carry)
            s += '1';

        reverse(s.begin(), s.end());
        return s;
    }
};