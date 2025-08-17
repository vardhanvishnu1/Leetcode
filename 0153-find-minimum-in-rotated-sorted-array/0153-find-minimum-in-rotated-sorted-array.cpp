class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size()-1;
        int mid ;
        
        int target = -5000;
        int ans = INT_MAX;
        while(lo<hi){
            mid = lo + (hi-lo)/2;
            if(nums[mid]>nums[hi]){
                // ans=min(ans,nums[mid]);
                lo = mid+1;
            }
            else{
                // ans=min(ans,nums[mid]);
                hi = mid;
            }
        }
        return nums[hi];
    }
};