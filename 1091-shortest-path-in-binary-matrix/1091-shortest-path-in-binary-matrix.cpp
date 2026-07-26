class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]==1||grid[n-1][n-1]==1) return -1;
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        pq.push({0,0,0});
        dist[0][0] = 0;
        vector<vector<int>>dir = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
        while(!pq.empty()){
            auto [dr,i,j] = pq.top();
            pq.pop();
            if(dr>dist[i][j]) continue;
            for(int d=0;d<8;d++){
                int ni = i + dir[d][0];
                int nj = j + dir[d][1];
                if(ni<0||nj<0||ni>=n||nj>=n||grid[ni][nj]==1) continue;
                if(dr+1<dist[ni][nj]){
                    dist[ni][nj] = dr+1;
                    pq.push({dist[ni][nj],ni,nj});
                }
            }
        }
        if(dist[n-1][n-1]==INT_MAX) return -1;
        return dist[n-1][n-1]+1;
    }
};