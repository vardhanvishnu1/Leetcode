class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.begin()+n);
        vector<vector<int>>ans;
        for(int i=0;i<=n-3;i++){
            if(i>0&&nums[i]==nums[i-1]) continue;
           int rem = 0-nums[i];
           int lo =i+1;int hi = n-1;
           while(lo<hi){
                if(nums[lo]+nums[hi]==rem){
                    ans.push_back({nums[i],nums[lo],nums[hi]});
                    while(lo<hi&&nums[lo+1]==nums[lo]) lo++;
                    while(lo<hi&&nums[hi-1]==nums[hi]) hi--;
                    lo++;
                    hi--;
                }
                while(lo<hi&&nums[lo]+nums[hi]>rem) hi--;
                while(lo<hi&&nums[lo]+nums[hi]<rem) lo++;
           }
        }
        return ans;
    }
};