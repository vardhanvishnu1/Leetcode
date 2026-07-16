class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int mx = INT_MIN;
        vector<int>pre(n);
        for(int i=0;i<n;i++){
            mx = max(mx,nums[i]);
            int x = gcd(nums[i],mx);
            pre[i] = x;
        }
        sort(pre.begin(),pre.end());
        int i=0;int j=n-1;
        long long ans = 0;
        while(i<j){
            ans+=gcd(pre[i],pre[j]);
            i++;j--;
        }
        return ans;
    }
};