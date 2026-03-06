class Solution {
public:
bool dfs(bool c,int node,vector<bool>&visited,vector<vector<int>>& graph,vector<int>&col){
    visited[node] = true;
    col[node] = c;
    for(auto neigh : graph[node]){
        if(!visited[neigh]){
            if(!dfs(!c,neigh,visited,graph,col)) return false;
        }
        else{
            if(col[neigh]==c) return false;
        }
    }
    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>col(n,-1);
        vector<bool>visited(n,false);
        bool c = true;
        for(int i=0;i<n;i++){
            if(visited[i]) continue;
            for(auto el : graph[i]){
                if(!dfs(c,el,visited,graph,col)) return false;
            }
        }
        return true;
    }
};