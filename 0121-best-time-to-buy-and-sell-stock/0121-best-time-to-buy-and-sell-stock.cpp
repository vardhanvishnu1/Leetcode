class Solution {
public:
    // int solve(int i,int buy,vector<int>& prices,vector<vector<int>>&dp){
    //     if(i==prices.size()) return 0;
    //     if(dp[i][buy]!=-1) return dp[i][buy];
    //     if(buy){
    //         int b = -prices[i]+solve(i+1,0,prices,dp);
    //         int nb = solve(i+1,1,prices,dp);
    //         return dp[i][buy] = max(b,nb);
    //     }
    //     else
    //         int sell = prices[i];
    //         int not_sell = solve(i+1,0,prices,dp);
    //         return dp[i][buy] = max(sell,not_sell);
    //     }
    // }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            for(int j = 0;j<2;j++){
                if(j){
                    dp[i][j] = max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                }
                else{
                    dp[i][j] = max(dp[i+1][0],prices[i]);
                }
            }
        }
        return dp[0][1];
    }
};