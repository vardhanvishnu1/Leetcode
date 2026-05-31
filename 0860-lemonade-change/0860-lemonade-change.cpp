class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int five = 0;
        int ten = 0;
        int twenty = 0;
        for(int i=0;i<n;i++){
            if(bills[i]==5){
                five++;
            }
            else{
                if(bills[i]==10) ten++;
                else twenty++;
                int rem = bills[i]-5;
                while(rem>=20&&twenty>0) {rem-=20;twenty--;}
                while(rem>=10&&ten>0) {rem-=10;ten--;}
                while(rem>=5&&five>0){five--;rem-=5;}
                if(rem>0) return false;
            }
        }
        return true;
    }
};