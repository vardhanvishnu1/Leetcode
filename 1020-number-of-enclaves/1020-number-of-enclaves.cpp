class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>&visited){
        if(i<0||j<0||i>=grid.size()||j>=grid[i].size()||visited[i][j]) return;
        visited[i][j] = true;
        if(grid[i][j]==1){
            grid[i][j]=0;
        }
        else{
            return;
        }
        dfs(i+1,j,grid,visited);dfs(i-1,j,grid,visited);dfs(i,j+1,grid,visited);dfs(i,j-1,grid,visited);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i=0;i<m;i++){
            if(visited[i][0]) continue;
            if(grid[i][0]==0) {continue;}
            else{
                dfs(i,0,grid,visited);
            }
            visited[i][0]=true;
        }
        for(int i=0;i<m;i++){
            if(visited[i][grid[i].size()-1]) continue;
            if(grid[i][grid[i].size()-1]==0) {continue;}
            else{
                dfs(i,grid[i].size()-1,grid,visited);
            }
            visited[i][grid[i].size()-1]=true;
        }
        for(int i=0;i<grid[0].size();i++){
            if(visited[0][i]) continue;
            if(grid[0][i]==0) {continue;}
            else{
                dfs(0,i,grid,visited);
            }
            visited[0][i]=true;
        }
        for(int i=0;i<grid[0].size();i++){
            if(visited[m-1][i]) continue;
            if(grid[m-1][i]==0) {continue;}
            else{
                dfs(m-1,i,grid,visited);
            }
            visited[m-1][i]=true;
        }
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j =0;j<grid[i].size();j++){
                if(grid[i][j]==1) ans++;
            }
        }
        return ans;
    }
};