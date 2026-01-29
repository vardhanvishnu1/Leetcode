class Solution {
public:
vector<long long> runDijkstra(long long start, int n, const vector<vector<pair<long long,long long>>>& adj) {
    vector<long long> dis(26,LLONG_MAX);
    priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
    dis[start] = 0;
    pq.push({0,start});
    while(!pq.empty()){
        long long d = pq.top().first;
        long long u = pq.top().second;
        pq.pop();
        if(d>dis[u]) continue;
        for (auto& edge : adj[u]) {
            long long weight = edge.first;
            long long v = edge.second;
            if (dis[u] + weight < dis[v]) {
                dis[v] = dis[u] + weight;
                pq.push({dis[v], v});
            }
        }
    }
    return dis;
}
long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long ans =0;
        vector<vector<pair<long long,long long>>>adj(26);
        int n = original.size();
        for(long long i=0;i<n;i++){
            adj[original[i]-'a'].push_back({cost[i],changed[i]-'a'});
        }
        vector<vector<long long>>dist(26);
        for(long long i=0;i<26;i++){
            dist[i] = runDijkstra(i,n,adj);
        }
        for(long long i=0;i<source.size();i++){
            if(source[i]!=target[i]){
                if(dist[source[i]-'a'][target[i]-'a']==LLONG_MAX) return -1;
                ans+=dist[source[i]-'a'][target[i]-'a'];
            }
        }
        return ans;
    }
};