class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<long long>pre(n,1);
        vector<long long>suf(n,1);
        pre[0] = nums[0];
        suf[n-1] = nums[n-1];
        for(int i=1;i<=2;i++){
            pre[i] = pre[i-1]*nums[i];
        }
        for(int i=n-2;i>=n-3;i--){
            suf[i] = suf[i+1]*nums[i];
        }
        vector<long long>ans;
        for(int i=0;i<3;i++){
            long long cur = pre[i];
            if(n+i-2<n) cur*=suf[n+i-2];
            ans.push_back(cur);
        }
        ans.push_back(suf[n-3]);
        sort(ans.begin(),ans.end());
        return (int)(ans[ans.size()-1]);
    }
};
