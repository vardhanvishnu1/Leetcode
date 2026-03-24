class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int o =0;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') o++;
            else if(s[i]==')') o--;
            ans = max(ans,o);
        }
    return ans;
    }
};