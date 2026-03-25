class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long n = grid.size();
        long long m = grid[0].size();
        vector<vector<long long>>h(n,vector<long long>(m)) ;
        for(long long i=0;i<n;i++){
            for(long long j=0;j<m;j++){
                h[i][j] = (long long)grid[i][j];
            }
        }
        for(long long i=0;i<n;i++){
            for(long long j=1;j<m;j++){
                h[i][j] = h[i][j-1]+grid[i][j];
            }
        }
        for(long long i=1;i<n;i++){
            for(long long j=0;j<m;j++){
                h[i][j] = h[i-1][j]+h[i][j];
            }
        }
        // horizantal check
        bool flag = false;
        for(long long i=0;i<=n-2;i++){
            if(h[i][m-1]*2==h[n-1][m-1]){
                flag = true;
                break;
            }
        }
        if(flag) return true;
        for(long long i=0;i<=m-2;i++){
            if(h[n-1][i]*2==h[n-1][m-1]){
                flag = true;
                break;
            }
        }
        return flag;
    }
};