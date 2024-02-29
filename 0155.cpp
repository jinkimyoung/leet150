
#include <stack>
using namespace std;

class MinStack {
public:
    stack<int> stk;
    stack<pair<int, int>> minStk;

    MinStack() {
    }
    
    void push(int val) {
        stk.push(val);
        if (minStk.empty() || val < minStk.top().first)
            minStk.push({val, 1});
        else if (val == minStk.top().first)
            minStk.top().second++;
    }
    
    void pop() {
        if (stk.top() == minStk.top().first) {
            minStk.top().second--;
            if (minStk.top().second == 0)   minStk.pop();
        }
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minStk.top().first;
    }
};
