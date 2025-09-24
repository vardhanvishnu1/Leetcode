class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int count1 =0;
        int count2 =0;
        vector<int>v;
        v.push_back(0);
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') count1++;
            else count2++;
            if(count1==count2) {
                v.push_back(i);
                if(i+1<=s.size()-1) v.push_back(i+1);
                count1=0;count2=0;
            }
        }
        for(int i=0;i<v.size();i+=2){
            int st =v[i]+1;
            int end = v[i+1];
            while(st<end) {
                ans+=s[st];
                st++;
            }
        }
        return ans;
    }
};