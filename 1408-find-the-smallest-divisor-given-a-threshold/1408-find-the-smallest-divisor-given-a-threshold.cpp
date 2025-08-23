class Solution {
public:
bool solve(vector<int>& nums, int threshold,int divisor){
    int sum =0;
    for(int i=0;i<nums.size();i++){
       sum += (nums[i] + divisor - 1) / divisor;
    }
    if(sum<=threshold) return true;
    return false;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int mx = INT_MIN;
        for(int i=0;i<nums.size();i++) mx = max(mx,nums[i]);
        int lo = 1;
        int hi = mx;
        int ans =1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(solve(nums,threshold,mid)){
                ans=mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return ans;
    }
};