class Solution {
private:
    int evaluateGroupLength(vector<char> const &chars, int start) {
        int end = start + 1;
        while (end < chars.size() && chars[end] == chars[start]) end++;
        return end - start;
    }

    void addLengthToChars(vector<char> &chars, string const groupLength, int start) {
        chars.resize(chars.size() + groupLength.size());
        for (int i = chars.size() - 1; i - groupLength.size() >= start; i--)
            chars[i] = chars[i-groupLength.size()];
        for (int i = 0; i < groupLength.size(); i++)
            chars[start+i] = groupLength[i];
    }
public:
    int compress(vector<char> &chars) {
        int i = 0;
        while (i < chars.size()) {
            int groupLength = evaluateGroupLength(chars, i);
            if (groupLength > 1) {
                chars.erase(chars.begin() + i + 1, chars.begin() + i + groupLength);
                addLengthToChars(chars, to_string(groupLength), i + 1);
                i += to_string(groupLength).size() + 1;
            } else {
                i++;
            }
        }
        return chars.size();
    }
};
