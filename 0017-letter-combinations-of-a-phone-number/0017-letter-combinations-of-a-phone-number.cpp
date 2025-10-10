class Solution {
public:
    void solve(string s,string curr,int idx,vector<string>&ans,unordered_map<int ,string>&u){
        if(idx==s.size()){
            ans.push_back(curr);
            return ;
        }
        string letters = u[s[idx]];
        for(auto el : letters){
            solve(s,curr+el,idx+1,ans,u);
        }
        return ;
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits==""){
            return ans;
        }
        unordered_map<int ,string>u={
             {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        solve(digits,"",0,ans,u);
        return ans;
    }
};