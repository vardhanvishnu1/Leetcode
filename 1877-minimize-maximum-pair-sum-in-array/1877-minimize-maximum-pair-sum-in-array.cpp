class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int lo =0;int hi = n-1;
        int ans = INT_MIN;
        while(lo<n/2){
            ans = max(ans,nums[lo]+nums[hi]);
            lo++;hi--;
        }
        return ans;
    }
};