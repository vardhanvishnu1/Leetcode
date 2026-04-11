class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>c(n+1);
        for(int i=0;i<n;i++){
            c[nums[i]].push_back(i);
        }
        int ans = INT_MAX;
        for(int i=0;i<=n;i++){
            if(c[i].size()>=3){
                int idx =0;
                int end = idx+2;
                while(idx<c[i].size()-2&&end<c[i].size()){
                    ans = min(ans,abs(c[i][idx+1]-c[i][idx])+abs(c[i][idx+1]-c[i][end])+abs(c[i][idx]-c[i][end]));
                    idx++;
                    end++;
                }
            }
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};