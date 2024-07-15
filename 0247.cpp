
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<char>> reversiblePairs = {
        {'0','0'}, {'1','1'}, {'6','9'}, {'8','8'}, {'9','6'},         
    };
    
    vector<string> findStrobogrammatic(int n) {
        queue<string> q;
        int length;
        
        if (n % 2 == 0) {
            length = 0;
            q.push("");
        }
        else
        {
            length = 1;
            q.push("0");
            q.push("1");
            q.push("8");
        }
        
        while (length < n)
        {
            length += 2;
            for (int i = q.size(); i > 0; i--)
            {
                string number = q.front();
                q.pop();
                
                for (auto pair : reversiblePairs)
                    if (length != n || pair[0] != '0')
                        q.push(pair[0]+number+pair[1]);
            }
        }
        
        vector<string> stroboNums;
        while (!q.empty())
        {
            stroboNums.push_back(q.front());
            q.pop();
        }
        return stroboNums;
    }
};


