class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int l = 0;
        int r = 0;
        int ans = 0;
        unordered_map<char,int>freq;
        while(r<n){
            freq[s[r]]++;
            while(l<r&&freq.size()==3){
                ans+=(n-(r-l)-l);
                freq[s[l]]--;
                if(freq[s[l]]==0) freq.erase(s[l]);
                l++;
            }
            r++;
        }
        return ans;
    }
};