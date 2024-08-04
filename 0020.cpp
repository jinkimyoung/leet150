
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for (char c : s)
        {
            switch (c)
            {
            case '(':
            case '{':
            case '[':
                stk.push(c);
                break;
            case ')':
            case '}':
            case ']':
                if (stk.empty()) return false;
                if ((c == ')' && stk.top() != '(') ||
                    (c == '}' && stk.top() != '{') ||
                    (c == ']' && stk.top() != '['))
                    return false;
                stk.pop();
                break;                
            }
        }
        return stk.empty();
    }
};

