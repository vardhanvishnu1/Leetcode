class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m  = mat.size();
        int n = mat[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>dist(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    dist[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

    vector<vector<int>>dir = {{1,0},{-1,0},{0,1},{0,-1}};
    while(!q.empty()){
        auto [curr_i,curr_j] = q.front();q.pop();
        for(int d = 0;d<4;d++){
                int new_i = curr_i + dir[d][0];
                int new_j = curr_j + dir[d][1];
                if(new_i<0||new_j<0||new_i>=m||new_j>=n||dist[new_i][new_j]!=-1) continue;
                dist[new_i][new_j] = dist[curr_i][curr_j] +1;
                q.push({new_i,new_j});
        }
    }
    return dist;
    }
};