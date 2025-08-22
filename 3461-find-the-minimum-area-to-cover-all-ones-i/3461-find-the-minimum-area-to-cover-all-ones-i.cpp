class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int left = INT_MAX;
        int right = INT_MIN;
        int up = INT_MAX;
        int down = INT_MIN;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
               if(grid[i][j]==1){
                  left=min(left,j);
                  up=min(up,i);
                  right=max(right,j);
                  down=max(down,i);
               }
            }   
        }
        return (right-left+1)*(down-up+1);
    }
};