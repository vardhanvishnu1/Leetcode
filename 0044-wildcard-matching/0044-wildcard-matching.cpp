class Solution {
public:
    bool solve(int i,int j,string &s, string &p,vector<vector<int>>&dp){
        if(i<0){
            while(j>=0){
                if(p[j]!='*') return false;
                j--;
            }
            return true;
        }
        if(j<0) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==p[j])   if(solve(i-1,j-1,s,p,dp)) return dp[i][j] = true;
        if(p[j]=='?'){
             if(solve(i-1,j-1,s,p,dp)) return dp[i][j] = true;
        }
        if(p[j]=='*'){
            for(int k=i;k>=-1;k--){
                if(solve(k,j-1,s,p,dp)) return dp[i][j] = true;
            }
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.size(),vector<int>(p.size(),-1));
        return solve(s.size()-1,p.size()-1,s,p,dp);
    }
};