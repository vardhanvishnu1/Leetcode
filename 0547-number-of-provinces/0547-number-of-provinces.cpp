class Solution {
public:
    void dfs(int node,vector<vector<int>>& isConnected,vector<bool>&visited){
        visited[node] = true;
        for(int neigh=0;neigh<isConnected.size();neigh++){
            if(isConnected[node][neigh]&&!visited[neigh]){
                dfs(neigh,isConnected,visited);
            }
        }
    }   
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0;
        int n = isConnected.size();
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                ans++;
                dfs(i,isConnected,visited);
            }
        }
        return ans;
    }
};