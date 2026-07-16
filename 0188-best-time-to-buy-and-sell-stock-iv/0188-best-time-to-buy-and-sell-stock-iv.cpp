class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
         int n = prices.size();
       vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        for(int i=n-1;i>=0;i--){
            for(int j = 1;j<=k;j++){
                
                    dp[i][1][j] = max(-prices[i]+dp[i+1][0][j],dp[i+1][1][j]);
       
              
                    dp[i][0][j] = max(dp[i+1][0][j],prices[i]+dp[i+1][1][j-1]);
      
            }
        }
        return dp[0][1][k]; 
    }
};