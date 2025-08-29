class Solution {
public:
    long long flowerGame(int n, int m) {
        long long count = 1;
        long long e1 =0;
        long long e2=0;
        long long o1=0;
        long long o2 =0;
        if(n%2==0){
            e1=n/2;
            o1=n/2;

        }
        else{
            e1=n/2;
            o1=e1+1;
        }
        if(m%2==0){
            e2=m/2;
            o2=m/2;

        }
        else{
            e2=m/2;
            o2=e2+1;
        }
        return o1*e2+e1*o2;
    }
};