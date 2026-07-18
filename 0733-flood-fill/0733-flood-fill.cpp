class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int org = image[sr][sc];
        if (org == color)
    return image;
        queue<pair<int,int>> q;
q.push({sr, sc});
image[sr][sc] = color;
 vector<vector<int>>dir = {{1,0},{-1,0},{0,1},{0,-1}};
while (!q.empty()) {
    auto [i, j] = q.front();
    q.pop();

    for (auto &d : dir) {
        int ni = i + d[0];
        int nj = j + d[1];

        if (ni < 0 || nj < 0 || ni >= m || nj >= n)
            continue;

        if (image[ni][nj] == org) {
            image[ni][nj] = color;
            q.push({ni, nj});
        }
    }
}
return image;
    }
};