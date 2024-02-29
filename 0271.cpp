
// to_string(), stoi()

#include <string>
#include <vector>
using namespace std;

class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string result;

        for (string str : strs)
            result = result + to_string(str.length()) + "#" + str;
        return result;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string>  result;
        int sIdx = 0, eIdx = s.find("#");
        while (eIdx != string::npos)
        {
            int size = stoi(s.substr(sIdx, eIdx-sIdx));
            result.push_back(s.substr(eIdx+1, size));
            sIdx = eIdx+1 + size;
            eIdx = s.find("#", sIdx);
        }
        return result;
    }
};