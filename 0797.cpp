class Solution {
    void pushPaths(vector<vector<int>> &paths, vector<vector<int>> const &graph, int startNode, vector<int> currentPath) {
        if (startNode == graph.size() - 1) {
            paths.push_back(currentPath);
            return;
        }
        if (graph[startNode].empty()) {
            return;
        }
        for (int neighbor : graph[startNode]) {
            currentPath.push_back(neighbor);
            pushPaths(paths, graph, neighbor, currentPath);
            currentPath.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        vector<vector<int>> paths;
        pushPaths(paths, graph, 0, {0});
        return paths;
    }
};
