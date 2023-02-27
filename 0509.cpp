#define UNKNOWN -1

class Solution {
private:
    void buildFibs(int n, vector<int> &knownFibs) {
        if (knownFibs[n] != UNKNOWN) return;
        if (knownFibs[n-2] == UNKNOWN) buildFibs(n-2, knownFibs);
        if (knownFibs[n-1] == UNKNOWN) buildFibs(n-1, knownFibs);
        knownFibs[n] = knownFibs[n-1] + knownFibs[n-2];
    }
public:
    int fib(int n) {
        vector<int> knownFibs(n + 2, UNKNOWN);
        knownFibs[0] = 0;
        knownFibs[1] = 1;
        if (n > 1) buildFibs(n, knownFibs);
        return knownFibs[n];
    }
};
