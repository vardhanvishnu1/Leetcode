class Solution {
public:
    int MOD = 1e9+7;
    int solve(int g1,int g2,int i,vector<int>& nums,int (&dp)[201][201][201]){
        if(i==nums.size()){
            if(g1==0&&g2==0) return 0;
            if(g1==g2) return 1;
            return 0;
        }
        if(dp[i][g1][g2]!=-1) return dp[i][g1][g2];
        int t1 = solve(gcd(g1,nums[i]),g2,i+1,nums,dp);
        int t2 = solve(g1,gcd(g2,nums[i]),i+1,nums,dp);
        int t3 = solve(g1,g2,i+1,nums,dp);
        return dp[i][g1][g2] = (0LL +t1+t2+t3)%MOD;
    }
    int subsequencePairCount(vector<int>& nums) {
        int dp[201][201][201];
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,nums,dp);
    }
};