#define EMPTY -1

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, EMPTY));
        vector<pair<int,int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        int currentDirection = 0, i = 0, j = 0;
        while (head) {
            matrix[i][j] = head->val;
            int newI = i + directions[currentDirection].first;
            int newJ = j + directions[currentDirection].second;
            if ((newI >= m || newI < 0 || newJ >= n || newJ < 0 || matrix[newI][newJ] != EMPTY) && head->next) {
                currentDirection = (currentDirection + 1) % directions.size();
                continue;
            }
            i = newI;
            j = newJ;
            head = head->next;
        }
        return matrix;
    }
};
