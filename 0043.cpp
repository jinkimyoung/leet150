

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1[0] == '0' || num2[0] == '0')
            return "0";
        int m = num1.length(), n = num2.length();
        vector<int> result(m+n, 0);

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                int temp = (num1[i]-'0') * (num2[j]-'0');
                int sum = temp + result[i+j+1];

                result[i+j+1] = sum % 10;
                result[i+j] += (sum / 10);
            }
        }

        string s;
        for (int num : result)
        {
            if (!s.empty() || num != 0)
                s.push_back(num + '0');
        }
        return s.empty() ? "0" : s;
    }
};


class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.length(), n = num2.length();
        vector<int> res(m+n, 0);
        string s;

        for (int i = m-1; i >= 0; i--)
        {
            for (int j = n-1; j >= 0; j--)
            {
                int tmp = res[i+j+1] + (num1[i]-'0')*(num2[j]-'0');
                res[i+j+1] = tmp % 10;
                res[i+j] += (tmp / 10);
            }
        }
        for (int i = 0; i < m+n; i++)
        {
            if (!s.empty() || res[i] > 0)
                s.push_back(res[i]+'0');
        }
        return s.empty() ? "0" : s;
    }
};


