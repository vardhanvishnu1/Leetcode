class Solution {
public:
int solve(int i,int buy,vector<int>& prices,vector<vector<int>>&dp){
        if(i==prices.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy){
            int b = -prices[i]+solve(i+1,0,prices,dp);
            int nb = solve(i+1,1,prices,dp);
            return dp[i][buy] = max(b,nb);
        }
        else{
            int sell = prices[i]+solve(i+1,1,prices,dp);
            int not_sell = solve(i+1,0,prices,dp);
            return dp[i][buy] = max(sell,not_sell);
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return solve(0,1,prices,dp);
    }
};