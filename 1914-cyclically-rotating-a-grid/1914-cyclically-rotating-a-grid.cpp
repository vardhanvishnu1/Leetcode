class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int u =0;int l =0;
        int r =n-1;
        int b = m-1;
        while(l<r&&u<b){
            int len = r-l;
            int width = b-u;
            int perimeter = 2*len+2*width;
            int d = k%perimeter;
            while(d--){
                int temp = grid[u][l];
                for(int i=l;i<r;i++){
                    grid[u][i] = grid[u][i+1];
                }
                for(int i=u;i<b;i++){
                    grid[i][r] = grid[i+1][r];
                }
                for(int i=r;i>l;i--){
                    grid[b][i] = grid[b][i-1];
                }
                for(int i=b;i>u;i--){
                    grid[i][l] = grid[i-1][l];
                }
                grid[u+1][l] = temp;
            }
            u++;l++;
            b--;r--;
        }
        return grid;
    }
};