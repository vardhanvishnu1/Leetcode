class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        int m1 = INT_MAX;
        int m2 = INT_MAX;
        for(int i =1;i<n;i++){
            if(nums[i]<m1){
                m2 = m1;
                m1 = nums[i];

            }
            else{
               if(nums[i]<m2) m2 = nums[i];
            }
        }
        cout<<ans<<" "<<m1<<" "<<m2<<endl;
        return ans+m1+m2;
    }
};