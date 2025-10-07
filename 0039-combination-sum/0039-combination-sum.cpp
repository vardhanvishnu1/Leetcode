class Solution {
public:
    void solve(vector<int>& candidates, int target,vector<vector<int>>& ans,int idx,vector<int>v){
        if (target == 0) {
            ans.push_back(v);
            return;
        }
        if(idx==candidates.size() || target <0)
            return;
        v.push_back(candidates[idx]);
        solve(candidates, target - candidates[idx], ans, idx, v); 
        v.pop_back();
        solve(candidates, target, ans, idx + 1, v);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        solve(candidates,target,ans,0,{});
        return ans;
    }
};