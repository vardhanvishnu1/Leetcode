class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int lo =0;
        int hi = n-1;
        int mid;
        while(lo<=hi){
            mid = lo + (hi-lo)/2;
            if(mid==0) {
                if(nums[mid]!=nums[mid+1]) return nums[mid];
                lo = mid+1;
            }
            else if(nums[mid]!=nums[mid-1]&&nums[mid]!=nums[mid+1]){
                return nums[mid];
            }
            else{
                if(nums[mid]==nums[mid-1]){
                    if((mid+1)&1) hi = mid-1;
                    else lo = mid+1;
                }
                else{
                    if((mid+2)&1) hi = mid-1;
                    else lo = mid+1;
                }
            }
        }
        return nums[hi];
    }
};