class Solution {
public:
    void solve(vector<int>nums,vector<vector<int>>&ans,int sum,int idx,vector<int>v,int k){
        if(sum<0) return;
        if(idx==nums.size()){
            if(v.size()==k&&sum==0) ans.push_back(v);
            return; 
        }
        v.push_back(nums[idx]);
        solve(nums,ans,sum-nums[idx],idx+1,v,k);
        v.pop_back();
        solve(nums,ans,sum,idx+1,v,k);
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums = {1,2,3,4,5,6,7,8,9};
        vector<vector<int>>ans;
        solve(nums,ans,n,0,{},k);
        return ans;
    }
};