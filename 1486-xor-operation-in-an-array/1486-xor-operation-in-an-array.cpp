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
        int x = start;
        start>>=1;
        return ((xor_(start-1)^xor_(start+n-1))<<1)|((x&1)&(n&1));
    }
};