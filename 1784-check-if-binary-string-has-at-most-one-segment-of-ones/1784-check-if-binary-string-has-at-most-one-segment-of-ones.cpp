class Solution {
public:
    bool checkOnesSegment(string s) {
        int cnt =0;
        int n = s.size();
        int curr = 1;
        for(int i=1;i<n;i++){
            if(s[i]=='1') {curr++;}
            else{
                if(curr>0) cnt++;
                curr=0;
            }
        }
        if(curr>0) cnt++;
        if(cnt<=1) return true;
        return false;
    }
};