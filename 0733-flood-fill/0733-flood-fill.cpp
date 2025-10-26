class Solution {
public:
struct PairHash {
        size_t operator()(const pair<int, int>& p) const {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };

void solve(vector<vector<int>>& image, int sr, int sc, int color,int initial){
    vector<vector<int>>dir = {{0,1},{0,-1},{1,0},{-1,0}};
    queue<pair<int,int>>q;
    unordered_set<pair<int,int>,PairHash>visited;
    visited.insert({sr,sc});
    q.push({sr,sc});
    while(!q.empty()){
        auto [curr_r,curr_c] = q.front();
        q.pop();
        image[curr_r][curr_c] = color;
        for(int i=0;i<4;i++){
            int new_r = curr_r + dir[i][0];
            int new_c = curr_c + dir[i][1];
            if(new_r<0||new_c<0||new_r>=image.size()||new_c>=image[0].size()) continue;
            if(image[new_r][new_c]==initial&&visited.find({new_r,new_c})==visited.end()){
                image[new_r][new_c] = color;
                q.push({new_r,new_c});
                visited.insert({new_r,new_c});
            }
        }
    }
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image; 
        solve(image,sr,sc,color,image[sr][sc]);
        return image;
    }
};