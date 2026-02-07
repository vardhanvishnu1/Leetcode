class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==1) return 0;
        sort(nums.begin(),nums.end());
        int ans = INT_MAX;
        int l =0;int r = 1;
        // 1 2 5 
        while(r<n&&l<n&&l<=r){
            while(r<n&&((float)(1.0*nums[r])/(k*1.0))<=nums[l]) r++;
            ans = min(ans,l+(n-1-r)+1);
            l++;
        }
        return ans;
    }
};