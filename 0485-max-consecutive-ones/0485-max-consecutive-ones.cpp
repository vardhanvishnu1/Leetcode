class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int cnt = 0;
        for(auto el : nums){
            if(el==1) cnt++;
            else{
                ans = max(cnt,ans);
                cnt = 0;
            }
        }
        ans = max(ans,cnt);
        return ans;
    }
};