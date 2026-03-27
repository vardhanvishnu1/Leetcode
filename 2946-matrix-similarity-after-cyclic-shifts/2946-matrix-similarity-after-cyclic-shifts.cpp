class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        k = k%n;
       for(int i=0;i<m;i++){
         vector<int>cur = mat[i];
         reverse(cur.begin()+k,cur.end());
         reverse(cur.begin(),cur.begin()+k);
         reverse(cur.begin(),cur.end());
         if(cur!=mat[i]) return false;
       }
       return true;
    }
};