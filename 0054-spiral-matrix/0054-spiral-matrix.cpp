class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>ans;
        int l = 0;
        int r = m-1;
        int u = 0;
        int d = n-1;
        while(u<=d&&l<=r){
            for(int i=l;i<=r;i++){
                ans.push_back(matrix[u][i]);
            }
            u++;
            if(u>d) break;
            for(int i=u;i<=d;i++){
                ans.push_back(matrix[i][r]);
            }
            r--;
            if(l>r) break;
            for(int i=r;i>=l;i--){
                ans.push_back(matrix[d][i]);
            }
            d--;
            //if(u>d) break;
            for(int i=d;i>=u;i--){
                ans.push_back(matrix[i][l]);
            }
            l++;
            // if(l>r) break;
        }
        return ans;
    }
};