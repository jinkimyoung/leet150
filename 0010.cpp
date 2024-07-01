
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> cache(s.length() + 1, vector<bool>(p.length() + 1, false));
        cache[s.length()][p.length()] = true;

        for (int i = s.length(); i >= 0; i--) {
            for (int j = p.length() - 1; j >= 0; j--) {
                bool match = i < s.length() && (s[i] == p[j] || p[j] == '.');

                if ((j + 1) < p.length() && p[j + 1] == '*') {
                    cache[i][j] = cache[i][j + 2];
                    if (match) {
                        cache[i][j] = cache[i + 1][j] || cache[i][j];
                    }
                } else if (match) {
                    cache[i][j] = cache[i + 1][j + 1];
                }
            }
        }

        return cache[0][0];
    }
};


