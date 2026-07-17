class Solution {
public:
    bool solve(int sum,int idx,vector<int>& nums,vector<vector<int>>&dp){
        if(sum<0) return false;
        if(idx==nums.size()) return sum==0;
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        bool take = solve(sum-nums[idx],idx+1,nums,dp);
        bool not_take = solve(sum,idx+1,nums,dp);
        return dp[idx][sum] = take||not_take;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total_sum = accumulate(nums.begin(),nums.end(),0);
        if(total_sum&1) return false;
        vector<vector<int>>dp(n,vector<int>((total_sum/2)+1,-1));
        return solve(total_sum/2,0,nums,dp);
    }
};