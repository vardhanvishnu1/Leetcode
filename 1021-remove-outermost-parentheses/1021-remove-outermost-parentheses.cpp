class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        int cnt = 0;
        string ans = "";
        bool flag = false;
        int i = 0;
        while(i<n){
            if(s[i]=='(') {cnt++;if(!flag){flag = true;i++;continue;}}
            else cnt--;
            if(flag&&cnt==0) {flag=false;}
            else {
                ans+=s[i];}
            i++;
        }
        return ans;
    }
};