class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor) return 1;
        if(dividend==INT_MAX&&divisor==-1) return INT_MIN+1;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(divisor==1) return dividend;
        int sign = 1;
        if((dividend<0&&divisor>0)||(dividend>0&&divisor<0)) {sign*=-1;}
       long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);
        int ans =0;
        while(n>=d){
            long long p =0;
            while(n>=(d<<(p+1))) p++;
            ans+=(1<<p);
            if(ans>=INT_MAX&&sign==1) return INT_MAX;
            if(sign==-1&&ans>=INT_MAX) return INT_MIN;
            n-=(d<<p);
            
        }
        return ans*sign;
    }
};