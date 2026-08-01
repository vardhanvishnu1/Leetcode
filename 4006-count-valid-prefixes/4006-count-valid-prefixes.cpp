class Solution {
public:
    int countValidPrefixes(string s) {
        int n = s.size();
        int z = 0;
        int o = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='0') z++;
            else o++;
            if(abs(z-o)<=1) ans++;
        }
        return ans;
    }
};