class Solution {
public:
    bool solve(int mid,vector<int>& piles, int h){
        int cnt = 0;
        for(int i=0;i<piles.size();i++){
            if(cnt+((piles[i]+mid-1)/mid)>h){
                return false;
            }
            cnt+=(piles[i]+mid-1)/mid;
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int lo =1;
        int hi = *max_element(piles.begin(),piles.end());
        int mid;
        int ans = INT_MAX;
        while(lo<=hi){
            mid = lo + (hi-lo)/2;
            if(solve(mid,piles,h)){
                ans = min(mid,ans);
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        return ans;
    }
};