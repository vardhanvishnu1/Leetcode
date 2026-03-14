class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans =0;
        int n = nums.size();
        int curr_sum = nums[0];
        if(curr_sum==k) ans++;
        map<int,int>mp;
        mp[curr_sum] = 1;
        for(int i=1;i<n;i++){
            curr_sum+=nums[i];
            if(curr_sum==k) ans++;
            int target = curr_sum-k;
            if(mp.find(target)!=mp.end()) ans+=mp[target];
            mp[curr_sum]++;
        }
        return ans;
    }
};