class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int>ans;
        int cnt =0;
        ans.push_back(nums[0]);
        cnt++;
        for(int i=1;i<nums.size();i++){
           if(nums[i]==nums[i-1]){
                if(cnt+1<=k) {ans.push_back(nums[i]);cnt++;}
                //else cnt =0;
           }
           else {cnt =0;ans.push_back(nums[i]);cnt++;}
        }
        return ans;
    }
};