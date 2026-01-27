class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
       vector<vector<pair<int,int>>> adj(n);
        
        // Build graph: normal and reversed edges
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            // original edge
            adj[u].push_back({v, w});
            // reversed (with additional cost)
            adj[v].push_back({u, 2LL * w});
        }
        
        // Dijkstra
        const long long INF = LLONG_MAX / 4;
        vector<long long> dist(n, INF);
        dist[0] = 0;
        priority_queue<pair<long long,int>, 
            vector<pair<long long,int>>, greater<>> pq;
        pq.push({0, 0});
        
        while (!pq.empty()) {
            auto [cd, u] = pq.top();
            pq.pop();
            if (cd > dist[u]) continue;
            
            for (auto &pr : adj[u]) {
                int v = pr.first;
                long long cost = pr.second;
                if (dist[v] > cd + cost) {
                    dist[v] = cd + cost;
                    pq.push({dist[v], v});
                }
            }
        }
        
        return dist[n - 1] == INF ? -1 : dist[n - 1];
    }
};