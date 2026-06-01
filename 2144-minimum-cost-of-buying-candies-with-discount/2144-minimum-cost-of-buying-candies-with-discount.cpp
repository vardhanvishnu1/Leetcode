class Solution {
public:
    int minimumCost(vector<int>& cost) {
        // 2 2 5 6 7 9
        int n = cost.size();
        sort(cost.begin(),cost.end());
        vector<bool>bought(n,false);
        int ans =0;
        for(int i=n-1;i>=0;i-=3){
            if(i>=0) {bought[i]=true;ans+=cost[i];}
            if(i-1>=0) {bought[i-1]=true;ans+=cost[i-1];}
            if(i-2>=0) bought[i-2] =true;
        }
    return ans;
    }
};