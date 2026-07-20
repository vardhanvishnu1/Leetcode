class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        k%=(m*n);
        vector<int>ans;
        for(int i=0;i<m;i++){
            for(int j =0;j<n;j++){
                ans.push_back(grid[i][j]);
            }
        }
        reverse(ans.begin(),ans.begin()+n*m-k);
        reverse(ans.begin()+m*n-k,ans.end());
        reverse(ans.begin(),ans.end());
        int idx = 0;
        for(int i=0;i<m;i++){
            for(int j = 0;j<n;j++){
                grid[i][j] = ans[idx];
                idx++;
            }
        }
        return grid;
    }
};
// m = 4 n = 4
// 10 11 6 4 5 2 7 19 9 1 8 3 13 21 0 12
// 12 0 21 13 3 8 1 9 19 7 2 5 4 6 11 10

// m = 3 n = 3
// 1 2 3 4 5 6 7 8 9
// 9 1 2 3 4 5 6 7 8 