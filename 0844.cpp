#define BACKSPACE '#'

class Solution {
private:
    string processString(string const &s) {
        string processed = "";
        for (char c : s) {
            if (c == BACKSPACE) {
                if (processed.length())
                    processed.pop_back();
            } else {
                processed += c;
            }
        }
        return processed;
    }
public:
    bool backspaceCompare(string s, string t) {
        string processedS = processString(s);
        string processedT = processString(t);
        return processedS == processedT;
    }
};
