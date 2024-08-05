

#include <map>
#include <stack>
#include <algorithm>
using namespace std;

class FreqStack {
public:
    map<int, int> freq;
    map<int, stack<int>> stk;
    int max_freq = 0;

    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        max_freq = max(max_freq, freq[val]);
        stk[freq[val]].push(val);
    }
    
    int pop() {
        int top = stk[max_freq].top();
        stk[max_freq].pop();
        if (stk[max_freq].size() == 0)
            max_freq--;
        freq[top]--;
        return top;
    }
};

