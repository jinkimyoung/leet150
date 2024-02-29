
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s)
        {
            switch (c)
            {
            case '(':
            case '{':
            case '[':
                st.push(c);
                break;
            case ')':
            case '}':
            case ']':
                if (st.empty()) return false;
                if (c == ')' && st.top() == '(')
                    st.pop();
                else if (c == '}' && st.top() == '{')
                    st.pop();
                else if (c == ']' && st.top() == '[')
                    st.pop();
                else
                    return false;
            }
        }
        return st.empty();  // when input is '(' only
    }
};