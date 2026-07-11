class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l =0;
        int r =0;
        int mf = 0;
        int ans = 0;
        map<int,int>freq;
        while(r<n){
            freq[s[r]-'A']++;
            mf = max(mf,freq[s[r]-'A']);
            while((r-l+1)-mf>k){
                freq[s[l]-'A']--;
                l++;
            }
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};