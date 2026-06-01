class Solution {
public:
bool solve(vector<vector<int>>&dp,int n,int cnt,int idx,string s){
    if(cnt<0) return false;
    if(idx>=n){
        if(cnt==0) return true;
        return false;
    }
    if(dp[idx][cnt]!=-1) return dp[idx][cnt];
    bool ans =false;
    if(s[idx]=='*'){
        return dp[idx][cnt] = solve(dp,n,cnt-1,idx+1,s)||solve(dp,n,cnt+1,idx+1,s)||solve(dp,n,cnt,idx+1,s);
    }
    if(s[idx]=='(') return dp[idx][cnt] = solve(dp,n,cnt+1,idx+1,s);
    if(s[idx]==')') return dp[idx][cnt] = solve(dp,n,cnt-1,idx+1,s);
    return true;
}
    bool checkValidString(string s) {
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),-1));
        return solve(dp,s.size(),0,0,s);
    }
};