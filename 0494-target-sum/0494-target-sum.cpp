class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(abs(target)>sum) return 0;
        if((target+sum)&1) return 0;
        int req = (target+sum)/2;
        vector<int>dp(req+1,0);
        dp[0] = 1;
        for(auto el : nums){
            for(int j = req;j>=el;j--){
                dp[j]+=dp[j-el];
            }
        }
        return dp[req];
    }
};