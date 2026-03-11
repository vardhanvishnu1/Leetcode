class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int x = n;
        int cnt =0;
        while(x>0){
            cnt++;
            x/=2;
        }
        int y = (1<<cnt)-1;
        return (n^y);
    }
};