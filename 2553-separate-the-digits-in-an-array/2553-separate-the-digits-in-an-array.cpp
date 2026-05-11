class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            string x = to_string(nums[i]);
            for(int i=0;i<x.size();i++){
                ans.push_back((int)(x[i]-'0'));
            }
        }
        return ans;
    }
};