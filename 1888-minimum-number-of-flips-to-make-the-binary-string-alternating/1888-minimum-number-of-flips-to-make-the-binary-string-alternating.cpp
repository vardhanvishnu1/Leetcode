class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string test1 = "";
        for(int i=0;i<2*n;i++){
            if(i&1) test1+="1";
            else test1+="0";
        }
        string test2 = "";
        for(int i=0;i<2*n;i++){
            if(i&1) test2+="0";
            else test2+="1";
        }
        int diff1 =0;
        int diff2 =0;
        int ans = INT_MAX;
        string doubled = s+s;
        for(int i=0;i<2*n;i++){
                if(doubled[i]!=test1[i]) diff1++;
                if(doubled[i]!=test2[i]) diff2++;
            
            if(i>=n){
                if(doubled[i-n]!=test1[i-n]) diff1--;
                if(doubled[i-n]!=test2[i-n]) diff2--;
            }
            if(i>=n-1) ans = min({ans,diff1,diff2});
        }
        return ans;
    }
};