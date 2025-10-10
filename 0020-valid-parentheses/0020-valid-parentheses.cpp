class Solution {
public:
    bool isValid(string s) {
        int count1 = 0;
        int count2 =0;
        stack<char>st;
        if(s.size()&1) return false;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('||s[i]=='['||s[i]=='{') st.push(s[i]);
            if(st.empty()&&(s[i]==')'||s[i]==']'||s[i]=='}')) return false;
            else if(s[i]==')'){
                if(st.top()!='(') return false;
                st.pop();
            }
            else if(s[i]==']'){
                if(st.top()!='[') return false;
                st.pop();
            }
            else if(s[i]=='}'){
                if(st.top()!='{') return false;
                st.pop();
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};