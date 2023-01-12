class Solution {
public:
    void dfs(int node, int prevNode, vector<vector<int>>& adjVec,string& labels, vector<int>& solution, vector<int>& freqMap) {
        int prevCount = freqMap[labels[node] - 'a'];
        freqMap[labels[node] - 'a'] += 1;
        for (int nextNode : adjVec[node]) {
            if (prevNode == nextNode) continue;
            dfs(nextNode, node, adjVec, labels, solution, freqMap);
        }
        solution[node] = freqMap[labels[node] - 'a'] - prevCount;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adjVec(n, vector<int>());
        vector<int> freqMap = vector<int>(26, 0);
        for (vector<int>& it : edges) {
            adjVec[it[0]].push_back(it[1]);
            adjVec[it[1]].push_back(it[0]);
        }
        vector<int> solution(n, 0);
        dfs(0, 0, adjVec, labels, solution, freqMap);

        return solution;
    }
};
