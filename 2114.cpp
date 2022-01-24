/*
    -> 2114. Maximum Number of Words Found in Sentences
    - A sentence is a list of words that are separated by a single space with no leading or trailing spaces.
    - You are given an array of strings sentences, where each sentences[i] represents a single sentence.
    - Return the maximum number of words that appear in a single sentence.
*/

#include <vector>
#include <string>

class Solution {

public:

    int mostWordsFound(std::vector<std::string>& sentences) {
        int currentMax = 0;
        for (std::string sentence : sentences) {
            int currentCount = 1;
            for (auto it = sentence.begin(); it != sentence.end(); it++) {
                if (*it == ' ')
                    currentCount++;
            }
            if (currentCount > currentMax)
                currentMax = currentCount;
        }
        return currentMax;
    }
};
