class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int q = queries.size();
        vector<int>comp(n);
        comp[0] = 0;
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]<=maxDiff) comp[i] = comp[i-1];
            else comp[i] = comp[i-1]+1;
        }
        vector<bool>ans;
        for(auto q : queries){
            if(comp[q[0]]==comp[q[1]]) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};