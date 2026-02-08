class Solution {
public:

    bool dfs(int node,int c,vector<vector<int>>& graph,vector<int> &col){
        col[node] = c;
        for(auto neigh : graph[node]){
            if(col[neigh]==-1){
                if(!dfs(neigh,!c,graph,col)) return false;
            }
            else{
                if(col[neigh]!=-1&&col[neigh]==c) return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>col(n,-1);
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                if(!dfs(i,0,graph,col)) return false;
            }
        }
        return true;
    }
};