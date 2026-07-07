class Solution {
public:
    long long sumAndMultiply(int n) {
        long long ans = 0;
        long long sum = 0;
        long long p = 1;
        while(n>0){
            int cur = n%10;
            if(cur!=0){
                ans = cur*p+ans;
                p*=10;
                sum+=cur;
            }
            n/=10;
        }
        return ans*sum;
    }
};