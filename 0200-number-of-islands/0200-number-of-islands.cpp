class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans =0;
        int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        for(int i=0;i<m;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j]=='0') continue;
                ans++;
                grid[i][j] = '0';
                queue<pair<int,int>>q;
                q.push({i,j});
                while(!q.empty()){
                    auto [ci,cj] = q.front();
                    q.pop();
                    for(int d =0;d<4;d++){
                        int ni,nj;
                        ni = ci + dir[d][0];
                        nj = cj + dir[d][1];
                        if(ni<0||nj<0||ni>=m||nj>=n||grid[ni][nj]=='0') continue;
                        else{
                            if(grid[ni][nj]=='1'){
                                grid[ni][nj] = '0';
                                q.push({ni,nj});
                            }
                            else{
                                continue;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};