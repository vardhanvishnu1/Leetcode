class Solution {
public:
    bool consecutiveSetBits(int n) {
        int cnt = 0 ;
        int pre  = 0;
        while(n>0){
            if((n&1)&&(pre==1)) cnt++;
            if(n&1) pre = 1;
            else pre =0;
            if(cnt>1) return false;
            n>>=1;
        }
        cout<<cnt<<endl;
        return  cnt==1;
    }
};