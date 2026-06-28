class Solution {
public:
    int solve(int idx, vector<int>& nums, int amount, vector<vector<int>>& dp) {
        if (amount == 0) return 1;  
        if (idx >= nums.size() || amount < 0) return 0;
        if (dp[idx][amount] != -1) return dp[idx][amount];
        int a = solve(idx, nums, amount - nums[idx], dp);  
        int b = solve(idx + 1, nums, amount, dp);             
        return dp[idx][amount] = a+b;
    }

    int change(int amount, vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(amount + 1, -1));
        return solve(0, nums, amount, dp);
    }
};