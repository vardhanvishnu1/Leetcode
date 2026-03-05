class Solution {
public:
    int minOperations(string s) {
        bool flag = true;
        int ans = INT_MAX;
        int n = s.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(flag){
                if(s[i]!='1') cnt++; 
                flag = false;
            }
            else{
                if(s[i]!='0') cnt++;
                flag = true;
            }
        }
        ans = min(ans,cnt);
        cnt =0;
        flag = false;
        for(int i=0;i<n;i++){
            if(flag){
                if(s[i]!='1') cnt++; 
                flag = false;
            }
            else{
                if(s[i]!='0') cnt++;
                flag = true;
            }
        }
ans = min(ans,cnt);
return ans;
    }
};