#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())   return false;

        unordered_map<char, int> m;
        for (char c : s)
            m[c]++;
        for (char c : t)
            m[c]--;
        for (char c : s)
            if (m[c])  return false;

        return true;
    }
};
