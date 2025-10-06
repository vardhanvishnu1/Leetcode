class Solution {
public:
    const long long MOD = 1000000007;

    long long power(long long x, long long y) {
        long long res = 1;
        x = x % MOD;
        while (y > 0) {
            if (y & 1)
                res = (res * x) % MOD;
            y = y >> 1;
            x = (x * x) % MOD;
        }
        return res;
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2; // positions with even digits (0,2,4,6,8)
        long long odd = n / 2;        // positions with prime digits (2,3,5,7)
        long long ans = (power(5, even) * power(4, odd)) % MOD;
        return ans;
    }
};
