class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned long long>dp(amount+1,0);
        dp[0] = 1;
        for(auto el : coins){
            for(int i=el;i<=amount;i++){
                dp[i]+=dp[i-el];
            }
        }
        return (int)dp[amount];
    }
};