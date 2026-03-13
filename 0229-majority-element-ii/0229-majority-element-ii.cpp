class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        int cnt1=0,cnt2 = 0;
        int can1 = -1;
        int can2 = -1;
        for(int i=0;i<n;i++){
          if(nums[i]==can1&&nums[i]!=can2){
            cnt1++;
          }
          else if(nums[i]==can2&&nums[i]!=can1){
            cnt2++;
          }
          else if(cnt1==0){
            can1 = nums[i];
            cnt1++;
          }
          else if(cnt2==0){
            can2 = nums[i];
            cnt2++;
          }
          else{
            cnt1--;cnt2--;
          }
        }
        cnt1=0;cnt2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==can1) cnt1++;
            else if(nums[i]==can2) cnt2++;
        }
        if(cnt1>n/3) ans.push_back(can1);
        if(cnt2>n/3) ans.push_back(can2);
        return ans;
    }
};