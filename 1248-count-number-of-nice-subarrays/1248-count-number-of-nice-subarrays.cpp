class Solution {
public:
    int solve(vector<int>& nums, int k){
        int n = nums.size();
        int ans =0;
        int l =0;
        int r = 0;
        int o =0;
        while(r<n){
            if(nums[r]&1) o++;
            while(l<=r&&o>k){
                if(nums[l]&1) o--;
                l++;
            }
            ans +=(r-l+1);
            r++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};