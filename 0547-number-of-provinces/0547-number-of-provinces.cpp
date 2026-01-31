class Solution {
public:
    void dfs(int node,vector<vector<int>>& isConnected,vector<int>&visited,int n){
        visited[node] = true;
        for(int j=0;j<n;j++){
            if(isConnected[node][j]&&!visited[j]){
                dfs(j,isConnected,visited,n);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>visited(n,false);
        int ans =0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                ans++;
                dfs(i,isConnected,visited,n);
            }
        }
        return ans;
    }
};