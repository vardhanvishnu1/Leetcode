class Solution {
public:
    int maxProduct(int n) {
        int m1 = -1;
        int m2 = -1;
        while(n>0){
            int x = n%10;
            if(x>=m1){
                swap(m2,m1);
                m1 = x;
            }
            else if(x>m2){
                m2 = x;
            }
            n/=10;
        }
        cout<<m1<<" "<<m2<<endl;
        return m1*m2;
    }
};