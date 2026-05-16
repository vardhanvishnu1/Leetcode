class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        vector<int>a;
        a.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]) continue;
            else a.push_back(nums[i]);
        }
        int lo =0;int hi = a.size()-1;
        int mid;
        int ans = INT_MAX;
        while(lo<=hi){
            mid = lo + (hi-lo)/2;
            if(a[mid]<=a[hi]){
                ans = min(ans,a[mid]);
                hi = mid-1;
            }
            else if(a[lo]<=a[mid]){
                ans = min(ans,a[lo]);
                lo = mid+1;
            }
        }
        return ans;
    }
};