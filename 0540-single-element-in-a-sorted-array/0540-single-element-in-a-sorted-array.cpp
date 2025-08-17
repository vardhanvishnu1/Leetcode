class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        for(int i=1;i<nums.size();i+=2){
            if(nums[i-1]!=nums[i]) return nums[i-1];
        }
        if(nums.size()%2!=0) return nums.back();
        return 0;
    }
};