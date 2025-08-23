class Solution {
public:
    bool canShip(vector<int>& weights, int days, int capacity) {
        int count = 1;  // at least one day
        int curr = 0;
        for (int w : weights) {
            if (w > capacity) return false;  // impossible if single package > capacity
            if (curr + w > capacity) {
                count++;
                curr = w;  // start new day
            } else {
                curr += w;
            }
        }
        return count <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int lo = *max_element(weights.begin(), weights.end());
        int hi = accumulate(weights.begin(), weights.end(), 0);
        int ans = hi;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (canShip(weights, days, mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};
