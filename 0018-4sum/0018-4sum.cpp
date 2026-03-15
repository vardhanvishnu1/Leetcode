class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            if(i>0&&nums[i]==nums[i-1]) continue;
            int j = i+1;
            while(j<n){
                int lo = j+1;int hi = n-1;
                long long rem = (long long)target-nums[i]-nums[j];
                while(lo<hi){
                    if(nums[lo]+nums[hi]==rem){
                        ans.push_back({nums[i],nums[j],nums[lo],nums[hi]});
                        while(lo<hi&&nums[lo+1]==nums[lo]) lo++;
                        while(lo<hi&&nums[hi-1]==nums[hi]) hi--;
                        lo++;
                        hi--;
                    }
                    while(lo<hi&&nums[lo]+nums[hi]<rem) lo++;
                    while(lo<hi&&nums[hi]+nums[lo]>rem) hi--;
                }
                while(j<n-1&&nums[j]==nums[j+1]) j++;
                j++;
            }
        }
        return ans;
    }
};