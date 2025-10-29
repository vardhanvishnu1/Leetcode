class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dist(n, vector<int>(m, -1));
        queue<pair<int, int>> q;

        // Step 1: Push all 0s into queue and mark distance 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // Step 2: Directions array
        vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        // Step 3: BFS traversal
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (auto& d : dir) {
                int nr = r + d[0];
                int nc = c + d[1];
                if (nr >= 0 && nc >= 0 && nr < n && nc < m && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        return dist;
    }
};

