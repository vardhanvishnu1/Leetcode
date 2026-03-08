class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]==1||grid[n-1][n-1]==1) return -1;
        vector<vector<int>>dir = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,-1},{-1,1}};
        queue<pair<int,int>>q;
        q.push({0,0});
        int d = 1;
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        visited[0][0] = true;
        while(!q.empty()){
            int sz = q.size();
            while(sz>0){
                auto [curr_i,curr_j] = q.front();q.pop();
                if(curr_i==n-1&&curr_j==n-1) return d;
                for(int i=0;i<8;i++){
                    int new_i,new_j;
                    new_i = curr_i+dir[i][0];
                    new_j = curr_j+dir[i][1];
                    if(new_i<0||new_j<0||new_i>=n||new_j>=n||grid[new_i][new_j]==1) continue;
                    if(new_i==n-1&&new_j==n-1) return d+1;
                    if(!visited[new_i][new_j]){
                        visited[new_i][new_j] = true;
                        q.push({new_i,new_j});
                    }
                }
                sz--;
            }
            d++;
        }
        return -1;
    }
};