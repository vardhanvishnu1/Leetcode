class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return;
        int l =0;
        int r =0;
        while(l<n&&nums[l]!=0) l++;
        r = l+1;
        while(r<n&&l<r){
            if(nums[r]!=0){
                if(l<n&&l<r) swap(nums[l],nums[r]);
                while(l<n&&nums[l]!=0&&l<r){
                    l++;
                }
            }
            r++;
        }
    }
};