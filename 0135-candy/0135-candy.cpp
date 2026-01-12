class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int>left(n,0);
        left[0] = 1;
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                left[i] = left[i-1]+1;
            }
            else{
                left[i] = 1;
            }
        }
        int ans =0;
        int curr = 1;int right = 1;
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                curr+=1;
            }
            else{
                curr = 1;
            }
            ans+=max(left[i],curr);
        }
        return ans+max(left[n-1],1);
    }
};
