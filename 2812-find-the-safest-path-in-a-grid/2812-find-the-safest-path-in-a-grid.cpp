class Solution {
public:
    bool check(vector<vector<int>>& safe, int x) {
        int n = safe.size();

        if (safe[0][0] < x || safe[n-1][n-1] < x)
            return false;

        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int>(n, 0));

        q.push({0,0});
        vis[0][0] = 1;
        int dx[] = {1,-1,0,0};
            int dy[] = {0,0,1,-1};

            while(!q.empty()) {
                auto [i,j] = q.front();
                q.pop();

                if(i == n-1 && j == n-1)
                    return true;

                for(int k=0;k<4;k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    if(ni>=0 && nj>=0 && ni<n && nj<n &&
                    !vis[ni][nj] &&
                    safe[ni][nj] >= x) {

                        vis[ni][nj] = 1;
                        q.push({ni,nj});
                    }
                }
            }

            return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]==1||grid[n-1][n-1]==1) return 0;
        vector<vector<int>>safe(n,vector<int>(n,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==1){q.push({i,j});safe[i][j]=0;}
            }
        }
        vector<vector<int>>dir = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int ci = curr.first;
            int cj = curr.second;
            for(int d =0;d<4;d++){
                int ni = ci + dir[d][0];
                int nj = cj + dir[d][1];
                if(ni<0||nj<0||ni>=n||nj>=n) continue;
                if(safe[ni][nj]==-1) {
                    safe[ni][nj] = safe[ci][cj]+1;
                    q.push({ni,nj});
                }
            }
        }
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        
        int lo = 0, hi = 2 * n, ans = 0;

        while(lo <= hi) {
            int mid = (lo + hi) / 2;

            if(check(safe, mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};