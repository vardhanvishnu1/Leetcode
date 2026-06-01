class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        int mx = 0;
        int mn = 0;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                mn+=1;
                mx+=1;
            }
            else if(s[i]==')'){
                mn-=1;
                mx-=1;
            }
            else{
                mn-=1;
                mx+=1;
            }
            if(mn<0) mn = 0;
            if(mx<0) return false;
        }
        return mn==0;
    }
};