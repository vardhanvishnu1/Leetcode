class Solution {
public:
    bool check(long long x,vector<int>& monsters,vector<long long>&temp_bonus){
        for(int i=0;i<monsters.size();i++){
            if(temp_bonus[i]+x>=monsters[i]){
                x-=monsters[i];
                if(x<0) x = 0;
            }
            else return false;
        }
        return true;
    }
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n = monsters.size();
        long long total = accumulate(monsters.begin(),monsters.end(),0LL);
        vector<long long>temp_bonus(n+2,0);
        int m = boosts.size();
        for(int i =0;i<m;i++){
            int st = boosts[i][0];
            int end = boosts[i][1];
            long long val = boosts[i][2];
            temp_bonus[st]+=val;
            temp_bonus[end+1]-=val;
        }
        for(int i=1;i<n+1;i++) temp_bonus[i] += 1LL*temp_bonus[i-1];
        long long ans = LLONG_MAX;
        long long lo = 0;
        long long hi = total;
        long long mid;
        while(lo<=hi){
            mid = lo + (hi-lo)/2;
            if(check(mid,monsters,temp_bonus)){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return ans;
    }
};