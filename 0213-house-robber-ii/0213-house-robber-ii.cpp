class Solution {
public:
 int solve(int start,int idx,vector<int>& nums,vector<int>&dp){
        if(idx==start) return nums[idx];
        if(idx<start) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int pick = nums[idx] + solve(start,idx-2,nums,dp);
        int not_pick = solve(start,idx-1,nums,dp);
        return dp[idx]=max(pick,not_pick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);
        return max(solve(1,n-1,nums,dp1),solve(0,n-2,nums,dp2));
    }
};