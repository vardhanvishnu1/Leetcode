class Solution {
public:
    bool isGood(vector<int>& nums) {
        map<int,int>freq;
        int n = nums.size()-1;
        int mx =INT_MIN;
        for(int i=0;i<=n;i++){
            freq[nums[i]]++;
            mx = max(mx,nums[i]);
        }
        if(n<mx) return false;
        for(int i=1;i<=mx;i++){
            if(i!=mx){
                if(freq[i]!=1) return false;
            }
            else{
                if(freq[mx]!=2) return false;
            }
        }
        return true;
    }
};