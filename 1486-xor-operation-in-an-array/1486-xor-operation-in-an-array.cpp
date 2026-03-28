class Solution {
public:
    int xor_(int n){
        if(n<0) return 0;
        if(n%4==1) return 1;
        if(n%4==2) return n+1;
        if(n%4==3) return 0;
        return n;
    }

    int xorOperation(int n, int start) {
        int s = start;
        s>>=1;
        return ((xor_(s-1)^xor_(s+n-1))<<1)|((start&1)&(n&1));
    }
};