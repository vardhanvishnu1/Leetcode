class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2) q.push({i,j});
            }
        }
        int time = 0;
        vector<vector<int>>dir = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int ci = q.front().first;
                int cj = q.front().second;
                q.pop();
                if(grid[ci][cj]==0) continue;
                for(int d=0;d<4;d++){
                    int ni = ci + dir[d][0];
                    int nj = cj + dir[d][1];
                    if(ni<0||nj<0||ni>=m||nj>=n||grid[ni][nj]==0) continue;
                    if(grid[ni][nj]==1){
                        grid[ni][nj]=2;
                        q.push({ni,nj});
                    }
                }
            }
            if(!q.empty()) time++;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return time;
    }
};