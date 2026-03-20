class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo =0;
        int hi = n-1;
        int mid;
        while(lo<=hi){
            mid = lo + (hi-lo)/2;
            if(nums[mid]==target) return true;
            if (nums[lo] == nums[mid] && nums[mid] == nums[hi]) {
                lo++;
                hi--;
            }
            else if(nums[lo]<=nums[mid]){
                if(target>=nums[lo]&&target<=nums[mid]) hi = mid-1;
                else lo = mid+1;
            }
            else{
                if(target>=nums[mid]&&target<=nums[hi]) lo = mid+1;
                else hi = mid-1;
            }
        }
        return false;
    }
};