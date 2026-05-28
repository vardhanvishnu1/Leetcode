class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l =0;
        int r =0;
        int n = s.size();
        map<char,int>freq;
        int ans =0;
        while(r<n){
            freq[s[r]]++;
            while(l<=r&&freq[s[r]]>=2){
                freq[s[l]]--;
                if(freq[s[l]]==0) freq.erase(s[l]);
                l++;
            }
            ans = max(ans,r-l+1);
            r++;
        }
    return ans;
    }
};