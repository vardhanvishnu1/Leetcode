class Solution {
public:
    int mn_pair(vector<int>&a,int n){
        int pos = -1;
        int mn = INT_MAX;
        for(int i=0;i<n-1;i++){
            if(a[i]+a[i+1]<mn){
                mn = a[i]+a[i+1];
                pos = i;
            }
        }
        return pos;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
            while(!is_sorted(nums.begin(),nums.end())){
                int idx = mn_pair(nums,n);
                nums[idx]+=nums[idx+1];
                nums.erase(nums.begin()+idx+1);   
                n = nums.size();
                ans++;
            }
        return ans;
    }
};