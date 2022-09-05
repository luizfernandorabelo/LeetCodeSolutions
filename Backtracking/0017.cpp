class Solution {
public:
    map<char,string> m;
    
    void pushCombinations(vector<string> &combinations, string &digits, int index, string current) {
        if (current.length() == digits.length()) {
            combinations.push_back(current);
            return;
        }
        string mappedString = m[digits[index]];
        for (char c : mappedString) {
            pushCombinations(combinations, digits, index + 1, current + c); 
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> combinations;
        if (digits.length() > 0)
            pushCombinations(combinations, digits, 0, "");
        return combinations;
    }
    
    Solution() {
        m['1'] = "";      m['2'] = "abc";  m['3'] = "def";
        m['4'] = "ghi";   m['5'] = "jkl";  m['6'] = "mno";
        m['7'] = "pqrs";  m['8'] = "tuv";  m['9'] = "wxyz";
    }
};