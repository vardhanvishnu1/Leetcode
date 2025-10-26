class Solution {
public:
int bfs(vector<vector<int>>& grid){
    int ans = 0;
    int fresh = 0;
    vector<vector<int>>dir  ={{1,0},{-1,0},{0,1},{0,-1}};
    queue<pair<int,int>>q;
    for(int i =0;i<grid.size();i++){
        for(int j =0;j<grid[i].size();j++){
            if(grid[i][j]==2){
                q.push({i,j});
            }
            if(grid[i][j]==1) fresh++;
        }
    }
   while (!q.empty() && fresh > 0) {
            int size = q.size();
            for (int k = 0; k < size; k++) {
                auto [r, c] = q.front();
                q.pop();
                for (auto& d : dir) {
                    int nr = r + d[0];
                    int nc = c + d[1];
                    if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2; // rot it
                        q.push({nr, nc});
                        fresh--;
                    }
                }
            }
        ans++;
        }
  return (fresh == 0) ? ans : -1;
    return ans;
}
    int orangesRotting(vector<vector<int>>& grid) {
        return bfs(grid);
    }
};