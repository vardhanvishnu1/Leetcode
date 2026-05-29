class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>pre(n,0);
        pre[0] = nums[0];
        for(int i=1;i<n;i++) pre[i] = pre[i-1]+nums[i];
        vector<int>suf(n,0);
        suf[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--) suf[i] = suf[i+1]+nums[i];
        if(k>=n) return pre[n-1];
        int ans = 0;
        for(int i=n-1;i>=n-k;i--){
    int rem = k - (n-i);

    if(rem == 0)
        ans = max(ans, suf[i]);
    else
        ans = max(ans, pre[rem-1] + suf[i]);
}
        ans = max(ans,pre[k-1]);
        return ans;
    }
};