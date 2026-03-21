class Solution {
public:
    bool solve(int mid,vector<int>& nums, int threshold){
        int cnt =0;
        for(int i=0;i<nums.size();i++){
            cnt+=(nums[i]+mid-1)/mid;
        }
        return (cnt<=threshold);
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo = 1;
        int hi = *max_element(nums.begin(),nums.end());
        int mid;
        int ans = INT_MAX;
        while(lo<=hi){
            mid = lo + (hi-lo)/2;
            if(solve(mid,nums,threshold)){
                ans = min(ans,mid);
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return ans;
    }
};