class Solution {
public:
    int jump(vector<int>& nums) {
        int ans =0;
        int i =0;
        int n = nums.size();
        if(n==1) return 0;
        while(i<n){
            if(nums[i]+i>=n-1){
                ans+=1;return ans;
            }
            int mx = i+1;
            for(int j=i+1;j<n&&j<=nums[i]+i;j++){
                if(nums[j]+j>=nums[mx]+mx){
                    mx = j;
                }
            }
            i=mx;
            ans+=1;
        }
        return ans;
    }
};