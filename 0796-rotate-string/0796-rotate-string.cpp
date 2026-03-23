class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        string d = s+s;
        for(int i=0;i<=d.size()-n;i++){
            if(d.substr(i,n)==goal) return true;
        }
        return false;
    }
};