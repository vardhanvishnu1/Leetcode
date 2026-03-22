#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Helper function to check if a "maxSum" limit is feasible
    bool canSplit(const vector<int>& nums, int k, int maxSum) {
        int currentSum = 0;
        int subarraysNeeded = 1;

        for (int num : nums) {
            if (currentSum + num > maxSum) {
                // Cannot fit this number in current subarray, start a new one
                subarraysNeeded++;
                currentSum = num;
                
                // If we exceed the allowed number of subarrays, it's impossible
                if (subarraysNeeded > k) return false;
            } else {
                currentSum += num;
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        // The smallest possible 'largest sum' is the maximum element in the array
        // The largest possible 'largest sum' is the sum of all elements
        int left = *max_element(nums.begin(), nums.end());
        long long right = accumulate(nums.begin(), nums.end(), 0LL);
        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canSplit(nums, k, mid)) {
                ans = mid;        // Try to find a smaller "largest sum"
                right = mid - 1;
            } else {
                left = mid + 1;   // Must increase the allowed sum
            }
        }

        return ans;
    }
};