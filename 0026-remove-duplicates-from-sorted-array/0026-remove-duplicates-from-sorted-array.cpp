class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int cnt =1;
        int l =0;
        int r =0;
        while(r<n){
            if(nums[l]!=nums[r]) {cnt++;nums[l+1] = nums[r];l++;}
            r++;
        }
        return cnt;
    }
};