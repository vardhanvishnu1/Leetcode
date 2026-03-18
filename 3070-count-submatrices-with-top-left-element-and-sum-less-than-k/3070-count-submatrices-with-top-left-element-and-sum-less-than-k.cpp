class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>rp = grid;
        for(int i=0;i<n;i++){
            for(int j =1;j<m;j++){
                rp[i][j] = rp[i][j-1]+grid[i][j];
            }
        }
        vector<vector<int>>cp = rp;
        for(int i=1;i<n;i++){
            for(int j =0;j<m;j++){
                cp[i][j] = cp[i-1][j]+rp[i][j];
            }
        }
        int ans =0;
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(cp[i][j]<=k) ans++;
            }
        }
        return ans;
    }
};