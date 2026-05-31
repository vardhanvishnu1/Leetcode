class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0;
        int idx = s.size()-1;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        for(int i=g.size()-1;i>=0&&idx>=0;i--){
            if(s[idx]>=g[i]){
                idx--;
                ans++;
            }
        }
        return ans;
    }
};