class Solution {
private:
    bool isOpeningChar(char c, map<char,char> const &validPairs) {
        for (auto validPair : validPairs)
            if (c == validPair.second) return true;
        return false;
    }
public:
    bool isValid(string s) {
        stack<char> charStack;
        map<char,char> validPairs = {{')', '('}, {']', '['}, {'}', '{'}};
        for (auto c : s) {
            if (isOpeningChar(c, validPairs)) {
                charStack.push(c);
            } else if (charStack.size() == 0) {
                return false;
            } else {
                if (charStack.top() != validPairs[c])
                    return false;
                charStack.pop();
            }
        }
        return charStack.size() == 0;
    }
};
