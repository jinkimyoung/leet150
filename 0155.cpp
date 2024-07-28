
#include <stack>
using namespace std;

class MinStack {
public:
    stack<int> stk;
    stack<int> minStk;

    MinStack() {
    }
    
    void push(int val) {
        stk.push(val);
        val = min(val, minStk.empty() ? val : minStk.top());
        minStk.push(val);
    }
    
    void pop() {
        stk.pop();
        minStk.pop();
    }
    
    int top() {
        return stk.top();        
    }
    
    int getMin() {
        return minStk.top();
    }
};