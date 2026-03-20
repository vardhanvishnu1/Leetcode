class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        int lo =0;
        int hi = n-1;
        int mid;
        while(lo<=hi){
            mid = lo + (hi-lo)/2;
            if(nums[lo]<=nums[mid]){
                ans = min(ans,nums[lo]);
                lo = mid+1;
            }
            else{
                hi = mid-1;
                ans = min(ans,nums[mid]);
            }
        }
        return ans;
    }
};