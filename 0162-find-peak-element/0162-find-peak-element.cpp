class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] < nums[mid+1]) {
            lo = mid + 1;  // peak is on the right
        } else {
            hi = mid;      // peak is at mid or on the left
        }
    }
    return lo;
    }
};