class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int a = 0;
        int b = 0;
        a = ((n)*(2+(n-1)*2))/2;
        b = ((n)*(4+(n-1)*2))/2;
        cout<<a<<" "<<b<<endl;
        return gcd(a,b);
    }
 };