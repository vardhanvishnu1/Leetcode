class Solution {
public:
    bool search(vector<int>& nums, int target) {
         int lo = 0;
        int hi = nums.size()-1;
        int mid;
        while(lo<=hi){
            mid = lo + (hi-lo)/2;
            if(nums[mid]==target){
                return true;
            }
            if(nums[lo] == nums[mid] && nums[mid] == nums[hi]){
                lo++;
                hi--;
            }
            else if(nums[lo]<=nums[mid]){
                if(target>=nums[lo]&&target<=nums[mid]) hi = mid-1;
                else lo = mid+1;
            }
            else{
                if(target<=nums[hi]&&target>=nums[mid]) lo=mid+1;
                else hi=mid-1;
            }
        }
        return false;
    }
};