class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int r = k-1;
        int ans = INT_MAX;
        for(int i=0;i<=n-k;i++){
            ans = min(ans,nums[r]-nums[i]);
            r++;
        }
        // 1 4 7 9
        // 3 3 2
        return ans;
    }
};