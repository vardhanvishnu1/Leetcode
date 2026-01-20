class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>ans(nums.size());
        for(int i=0;i<nums.size();i++){
            if(nums[i]==2){
                ans[i] = -1;
            }
            for(int j=1;j<nums[i];j++){
                if((j|j+1)==nums[i]){
                    ans[i] = j;
                    break;
                }
            }
        }
        return ans;
    }
};