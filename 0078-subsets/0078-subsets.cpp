class Solution {
public:
    void solve(vector<vector<int>>&ans,vector<int>nums,int idx,vector<int>temp){
        if(idx>=nums.size()) return;
        temp.push_back(nums[idx]);
        solve(ans,nums,idx+1,temp);
        ans.push_back(temp);
        temp.pop_back();
        solve(ans,nums,idx+1,temp);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        ans.push_back(temp);
        solve(ans,nums,0,temp);
        return ans;
    }
};