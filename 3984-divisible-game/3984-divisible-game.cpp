class Solution {
public:
    int divisibleGame(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        
        // Collect only unique PRIME factors from the array elements
        set<int> candidates;
        for (int x : nums) {
            int temp = x;
            for (int d = 2; d * d <= temp; d++) {
                if (temp % d == 0) {
                    candidates.insert(d);
                    while (temp % d == 0) temp /= d; // Strip out this prime completely
                }
            }
            if (temp > 1) {
                candidates.insert(temp); // The remaining part is prime
            }
        }
        
        // Edge case fallback
        if (candidates.empty()) {
            candidates.insert(2);
        }

        long long bestDiff = -1e18;
        long long bestK = -1;

        // Run Kadane's for prime candidates only
        for (int k : candidates) {
            long long current_max = -1e18;
            long long running_sum = 0;

            for (int num : nums) {
                long long val = (num % k == 0) ? num : -num;
                running_sum += val;
                if (running_sum > current_max) current_max = running_sum;
                if (running_sum < 0) running_sum = 0;
            }

            if (current_max > bestDiff) {
                bestDiff = current_max;
                bestK = k;
            }
        }

        long long safeDiff = ((bestDiff % MOD) + MOD) % MOD;
        long long safeK = bestK % MOD;
        return (safeDiff * safeK) % MOD;
    }
};