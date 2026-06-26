class Solution {
public:
 int solve(int n,int sum,int idx,vector<int>& coins, int amount,vector<vector<int>>&dp){
    if(sum==amount) return 0;
    if(sum>amount||idx==n) return INT_MAX;
    if(dp[sum][idx]!=-1) return dp[sum][idx];
    int take = INT_MAX;
    if (coins[idx] <= amount - sum){
    int res = solve(n,sum+coins[idx],idx,coins,amount,dp);
    if(res==INT_MAX) take = INT_MAX;
    else take = 1+res;
    }
    int skip = solve(n,sum,idx+1,coins,amount,dp);
    return dp[sum][idx] = min(take,skip);
}
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(amount+1,vector<int>(n,-1));
        int x =  (int)solve(n,0,0,coins,amount,dp);
        if(x==INT_MAX) return -1;
        return x;
    }
};