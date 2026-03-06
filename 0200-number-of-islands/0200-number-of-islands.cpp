class Solution {
public:
void dfs(int i,int j,int m,int n,vector<vector<char>>& grid,vector<vector<bool>>&visited){
    if(i<0||j<0||i>=m||j>=n||visited[i][j]||grid[i][j]=='0') return ;
    visited[i][j] = true;
    dfs(i+1,j,m,n,grid,visited);
    dfs(i-1,j,m,n,grid,visited);
    dfs(i,j+1,m,n,grid,visited);
    dfs(i,j-1,m,n,grid,visited);
}
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]=='0') continue;
                else{
                    if(!visited[i][j]){
                        dfs(i,j,m,n,grid,visited);
                        ans++;
                    }
                    else continue;
                }
            }
        }
        return ans;
    }
};