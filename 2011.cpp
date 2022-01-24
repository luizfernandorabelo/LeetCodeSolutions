/*
    -> 2011. Final Value of Variable After Performing Operations
    - There is a programming language with only four operations and one variable X:
        ++X and X++ increments the value of the variable X by 1.
        --X and X-- decrements the value of the variable X by 1.
    - Initially, the value of X is 0. Given an array of strings operations containing a list of operations, return the final value of X after performing all the operations.
*/

#include <vector>
#include <string>

class Solution {

public:

    int finalValueAfterOperations(std::vector<std::string>& operations) {
        int value = 0;
        for (std::string op : operations) {
            if (op == "X++" || op == "++X")
                value += 1;
            else
                value -= 1;
        }
        return value;
    }

};