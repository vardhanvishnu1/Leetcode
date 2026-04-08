class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();
        for(int i=0;i<q;i++){
            int st = queries[i][0];
            int end = queries[i][1];
            int gap = queries[i][2];
            int mul = queries[i][3];
            while(st<=end){
                nums[st]=(((long long)nums[st]%1000000007)*mul)%1000000007;
                st+=gap;
            }
        }
        int ans =0;
        for(int i=0;i<n;i++) ans^=nums[i];
        return ans;
    }
};