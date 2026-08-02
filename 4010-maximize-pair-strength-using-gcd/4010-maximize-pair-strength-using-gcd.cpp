class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for(int i=0;i<n;i++){
            for(int j =i+1;j<n;j++){
                long long x = gcd(nums[i],nums[j]);
                ans = max(ans,(1LL*nums[i]*nums[j])/(1LL*x*x));
            }
        }
        return ans;
    }
};