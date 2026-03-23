class Solution {
public:
    string removeOuterParentheses(string s) {
        int n  = s.size();
        string ans = "";
        int i =0;
        stack<char>st;
        while(i<n){
            if(s[i]=='(') st.push('(');
            else{
                if(st.size()!=1){
                    ans+="()";
                }
                st.pop();
            }
            i++;
        }
        return ans;
    }
};