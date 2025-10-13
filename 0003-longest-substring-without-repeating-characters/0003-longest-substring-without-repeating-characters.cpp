class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>st;
        int ans =  1;
        int count = 0;
        int n = s.size();
        int start = 0;
        if(n<=1) return n;
        int i =0;
        while(i<n){
            if(st.find(s[i])!=st.end()&&st[s[i]]>=start){
                start = st[s[i]]+1;
            }
            st[s[i]]=i;
            ans = max(ans,i-start+1);
            i++;
        }
        return ans;
    }
};