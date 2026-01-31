class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        vector<vector<int>>visited(n,vector<int>(m,0));
        vector<pair<int,int>>dir = {{1,0},{-1,0},{0,-1},{0,1}};
        int time =0;
        while(!q.empty()){
            int size = q.size();bool pushed = false;
            for(int r=0;r<size;r++){
                auto [i,j] = q.front();q.pop();
                for(int d=0;d<4;d++){
                    int new_i = i + dir[d].first;
                    int new_j = j + dir[d].second;
                    if(new_i<0||new_j<0||new_i>=n||new_j>=m||grid[new_i][new_j]==0||visited[new_i][new_j]||grid[new_i][new_j]==2) continue;
                    if(grid[new_i][new_j]==1){
                        visited[new_i][new_j] = true;
                        grid[new_i][new_j] = 2;
                        pushed=true;
                        q.push({new_i,new_j});
                    }
                }
            }
            if(pushed) time++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return time;
    }
};