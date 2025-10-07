class Solution {
public:
void solve(vector<int>& nums,vector<vector<int>>&ans,vector<int>v,int idx){
    if(idx==nums.size()){ 
        ans.push_back(v);
        return;
    }
    v.push_back(nums[idx]);
    solve(nums,ans,v,idx+1);
    v.pop_back();
    int next = idx + 1;
    while(next < nums.size() && nums[next] == nums[idx]) next++;
    solve(nums,ans,v,next);
    return;
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        solve(nums,ans,{},0);
        return ans;
    }
};