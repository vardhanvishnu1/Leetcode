class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int count =0 ;
       int i = s.size()-1;
       int idx = g.size()-1;
       while(i>=0&&idx>=0){
        if(s[i]>=g[idx]){
            count++;
            i--;
        }
        idx--;
       }
       return count;
    }
};