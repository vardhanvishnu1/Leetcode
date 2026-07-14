class Solution {
public:
    int MOD = 1e9+7;
    // int solve(int g1,int g2,int i,vector<int>& nums,int (&dp)[201][201][201]){
    //     if(i==nums.size()){
    //         if(g1==0&&g2==0) return 0;
    //         if(g1==g2) return 1;
    //         return 0;
    //     }
    //     if(dp[i][g1][g2]!=-1) return dp[i][g1][g2];
    //     int t1 = solve(gcd(g1,nums[i]),g2,i+1,nums,dp);
    //     int t2 = solve(g1,gcd(g2,nums[i]),i+1,nums,dp);
    //     int t3 = solve(g1,g2,i+1,nums,dp);
    //     return dp[i][g1][g2] = (0LL +t1+t2+t3)%MOD;
    // }
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(),nums.end());
        int dp[n+1][mx+1][mx+1];
        for(int i=0;i<=mx;i++){
            for(int j=0;j<=mx;j++){
                bool f1 = (i!=0&&j!=0);
                bool f2 = (i==j);
                if(f1&&f2){
                    dp[n][i][j] = 1;
                }
                else{
                    dp[n][i][j] = 0;
                }
            }
        }
        // memset(dp,-1,sizeof(dp));
        for(int i = n-1;i>=0;i--){
            for(int j = mx;j>=0;j--){
                for(int k = mx;k>=0;k--){
                    int t1 = dp[i+1][gcd(j,nums[i])][k];
                    int t2 = dp[i+1][j][gcd(k,nums[i])];
                    int t3 = dp[i+1][j][k];
                    dp[i][j][k] = (0LL+t1+t2+t3)%MOD;
                }
            }
        }
        return dp[0][0][0];
    }
};