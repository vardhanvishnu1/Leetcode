class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int>pre(n+1,0);
        vector<int>post(n+1,0);
        pre[0] = nums[0];
        post[n-1] = nums[n-1];
        for(int i=1;i<n;i++){
            pre[i] = pre[i-1]+nums[i];
        }
        for(int i=n-2;i>=0;i--){
            post[i] = post[i+1]+nums[i]; 
        }
        vector<int>ans(n);
        for(int i=1;i<n;i++){
            ans[i] = abs(post[i+1]-pre[i-1]);
        }
        ans[0] = post[1];
        return ans;
    }
};