class Solution {
public:
    int maxDepth = 0;
    const int MOD = 1e9 + 7;

    void dfs(int node, int parent, int depth,
             vector<vector<int>>& adj) {

        maxDepth = max(maxDepth, depth);

        for (int nxt : adj[node]) {
            if (nxt != parent) {
                dfs(nxt, node, depth + 1, adj);
            }
        }
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;

        if (n == 1) return 0;

        vector<vector<int>> adj(n + 1);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(1, 0, 0, adj);

        long long ans = 1;

        for (int i = 1; i < maxDepth; i++) {
            ans = (ans * 2) % MOD;
        }

        return ans;
    }
};