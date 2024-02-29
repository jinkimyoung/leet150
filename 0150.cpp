
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int ret, num1, num2;
        for (string token: tokens)
        {
            if (token.length() > 1 || isdigit(token[0]))
            {
                st.push(stoi(token));
                continue;
            }
            
            num2 = st.top();
            st.pop();
            num1 = st.top();
            st.pop();
            if (token == "+")   ret = num1 + num2;
            else if (token == "-")   ret = num1 - num2;
            else if (token == "*")   ret = num1 * num2;
            else if (token == "/")   ret = num1 / num2;
            st.push(ret);
        }
        return st.top();
    }
};
