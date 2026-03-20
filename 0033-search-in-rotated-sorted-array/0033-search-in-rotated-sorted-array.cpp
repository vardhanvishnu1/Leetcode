class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo =0;
        int hi = n-1;
        int mid;
        while(lo<=hi){
            mid = lo + (hi-lo)/2;
            if(nums[mid]==target) return mid;
            else if(nums[lo]<=nums[mid]){
                if(target<=nums[mid]&&nums[lo]<=target){
                    hi = mid-1;
                }
                else lo = mid+1;
            }
            else{
                if(target>=nums[mid]&&nums[hi]>=target){
                    lo = mid+1;
                }
                else hi = mid-1;
            }
        }
        return -1;
    }
};