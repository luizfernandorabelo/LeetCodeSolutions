class Solution {
private:
    bool isOperator(string const &token) {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }

    void pushResult(stack<int> &tokens, int n1, int n2, string const &op) {
        if (op == "+") tokens.push(n1 + n2);
        else if (op == "-") tokens.push(n1 - n2);
        else if (op == "*") tokens.push(n1 * n2);
        else tokens.push(n1 / n2);
    }
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> s;
        for (string token : tokens) {
            if (isOperator(token)) {
                int n2 = s.top(); s.pop();
                int n1 = s.top(); s.pop();
                pushResult(s, n1, n2, token);
            } else {
                s.push(atoi(token.c_str()));
            }
        }
        return s.top();
    }
};
