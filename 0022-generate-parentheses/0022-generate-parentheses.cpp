class Solution {
public:
    void solve(string s,int n,vector<string>&ans,int count1,int count2){
        if(count2>count1) return;
        if(s.size()/2==n){
            if(count1==count2) ans.push_back(s);
            return ;
        }
        solve(s+'(',n,ans,count1+1,count2);
        solve(s+')',n,ans,count1,count2+1);
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve("",n,ans,0,0);
        return ans; 
    }
};