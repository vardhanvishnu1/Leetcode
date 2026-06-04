class Solution {
public:
    int candy(vector<int>& ratings) {
        int  n = ratings.size();
        int ans =1 ;
        int i =1;
        while(i<n){
            while(i<n&&ratings[i]==ratings[i-1]){
                ans++;
                i++;
            }
            int up = 1;
            while(i<n&&ratings[i]>ratings[i-1]){
                up++;
                ans+=up;  
                i++;
            }
            int down = 1;
            while(i<n&&ratings[i]<ratings[i-1]){
                ans+=down;
                down++;
                i++;
            }
            if(down>up) ans+=(down-up);
        }
        return ans;
    }
};