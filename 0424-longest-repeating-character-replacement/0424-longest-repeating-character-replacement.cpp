class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l =0;
        int r = 0;
        int ans = 0;
        int max_freq = 0;
        map<int,int>freq;
        while(r<n){
            freq[s[r]-'A']++;
            max_freq = max(max_freq,freq[s[r]-'A']);
            int len = r-l+1;
            while(r-l+1-max_freq>k){
                freq[s[l]-'A']--;
                if(freq[s[l]-'A']==0) freq.erase(s[l]-'A');
                l++;
            }
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};