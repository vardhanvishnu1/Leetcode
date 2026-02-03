class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int cnt1 =0;int cnt2 =0;int cnt3 =0;
        int i =0;
        int j = 0;
        while(i<n-1&&nums[i+1]>nums[i]) i++;
        if(i-j+1<=1) return false;
        j = i;
        if(i>=n-1) return false;
        while(i<n-1&&nums[i+1]<nums[i]) i++;
        if(i-j+1<=1) return false;
        j = i;
        if(i>=n-1) return false;
        while(i<n-1&&nums[i+1]>nums[i]) i++;
        if(i-j+1<=1||i<n-1) return false;
        return true;
    }
};