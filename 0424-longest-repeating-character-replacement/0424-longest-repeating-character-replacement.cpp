class Solution {
public:
    int characterReplacement(string s, int k) {
        int l =0,r=0;
        vector<int>freq(26,0);
        int mf = INT_MIN;
        int ml = INT_MIN;
        int n = s.size();
        while(r<n){
            freq[s[r]-'A']++;
            mf = max(mf,freq[s[r]-'A']);
            while((r-l+1)-mf>k){
                freq[s[l]-'A']--;
                l++;
            }
            
                ml = max(ml,r-l+1);
            
            r++;
        }
        return ml;
    }
};