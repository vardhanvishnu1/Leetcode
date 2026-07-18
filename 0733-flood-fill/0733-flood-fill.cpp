class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int org = image[sr][sc];
        queue<tuple<int,int,int>>q;
        vector<vector<int>>dir = {{1,0},{-1,0},{0,1},{0,-1}};
        q.push({sr,sc,org});
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        visited[sr][sc] = true;
        image[sr][sc] = color;
        while(!q.empty()){
            auto [ci,cj,x] = q.front();
            org = x;
            q.pop();
            for(int d=0;d<4;d++){
                int ni = ci + dir[d][0];
                int nj = cj + dir[d][1];
                if(ni<0||nj<0||ni>=m||nj>=n||image[ni][nj]!=org||visited[ni][nj]) continue;
                visited[ni][nj] = true;
                int k = image[ni][nj];
                image[ni][nj]=color;
                q.push({ni,nj,k});
            }
        }
        return image;
    }
};