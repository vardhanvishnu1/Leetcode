class Solution {
public:
    bool can_complete(vector<int>& piles, int h, int k) {
        long long totalHours = 0;
        for (int i = 0; i < piles.size(); i++) {
            totalHours += (piles[i] + k - 1) / k; 
            if (totalHours > h) return false;   
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int mx = *max_element(piles.begin(), piles.end());
        int hi = mx;
        int ans = mx;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (can_complete(piles, h, mid)) {
                ans = mid;       
                hi = mid - 1;    
            } else {
                lo = mid + 1;    
            }
        }
        return ans;
    }
};
