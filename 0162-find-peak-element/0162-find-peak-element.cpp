class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1) return 0;
        nums.insert(nums.begin(),INT_MIN);
        nums.push_back(INT_MIN);
    int lo = 1, hi = nums.size() - 2;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if(nums[mid]>nums[mid+1]&&nums[mid]>nums[mid-1]) return mid-1;
        if (nums[mid] >= nums[mid-1]) {
            lo = mid + 1;  
        } else {
            hi = mid-1;      
        }
    }
    return 0;
    }
};