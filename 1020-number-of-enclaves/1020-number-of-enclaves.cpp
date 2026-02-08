class Solution {
public:
void dfs(int& count,int i,int j,int m,int n,vector<vector<int>>& grid){
    if(i<0||j<0||i>=m||j>=n||grid[i][j]==0) return;
    if(i!=0&&j!=0&&i!=m-1&&j!=n-1) {count--;}
    grid[i][j]=0;
    dfs(count,i+1,j,m,n,grid);
    dfs(count,i-1,j,m,n,grid);
    dfs(count,i,j+1,m,n,grid);
    dfs(count,i,j-1,m,n,grid);
}
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count =0;
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(grid[i][j] == 1) count++;
            }
        }
        for(int i=0;i<n;i++){
           if(grid[0][i]==1){
             
                dfs(count,0,i,m,n,grid);
           }
           if(grid[m-1][i]==1){
            
                dfs(count,m-1,i,m,n,grid);
           }
        }
        for(int i=0;i<m;i++){
           if(grid[i][0]==1){
       
                dfs(count,i,0,m,n,grid);
           }
           if(grid[i][n-1]==1){
           
                dfs(count,i,n-1,m,n,grid);
           }
        }
        return count;
    }
};