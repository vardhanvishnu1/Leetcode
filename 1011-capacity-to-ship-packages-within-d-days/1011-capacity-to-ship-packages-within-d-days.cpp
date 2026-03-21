class Solution {
public:
    bool solve(int mid,vector<int>& nums, int days){
        int cnt = 1;
        int cur = 0;
        for(int i=0;i<nums.size();i++){
            cur+=nums[i];
            if(cur>mid) {cnt++;cur=nums[i];}
        }
        return cnt<=days;
    }
    int shipWithinDays(vector<int>& nums, int days) {
        int lo = *max_element(nums.begin(),nums.end());
        int hi = accumulate(nums.begin(),nums.end(),0);
        int mid;
        int ans = hi;
        while(lo<=hi){
            mid = lo + (hi-lo)/2;
            if(solve(mid,nums,days)){
                ans = min(ans,mid);
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        return ans;
    }
};