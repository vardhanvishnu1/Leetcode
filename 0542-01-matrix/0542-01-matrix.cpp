class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>dist(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                }
                else{
                    dist[i][j] = INT_MAX;
                }
            }
        }
        vector<vector<int>>dir = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            int ci = q.front().first;
            int cj = q.front().second;
            q.pop();
            for(int d=0;d<4;d++){
                int ni = ci + dir[d][0];
                int nj = cj + dir[d][1];
                if(ni<0||nj<0||ni>=m||nj>=n||mat[ni][nj]==0||dist[ni][nj]!=INT_MAX) continue;
                dist[ni][nj]  = dist[ci][cj]+1;
                q.push({ni,nj});
            }
        }
    return dist;
    }
};