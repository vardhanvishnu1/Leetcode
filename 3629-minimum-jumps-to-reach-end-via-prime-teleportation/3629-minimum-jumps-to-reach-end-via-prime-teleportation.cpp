#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int maxVal = *max_element(nums.begin(), nums.end());
        
        // 1. Sieve of Eratosthenes
        vector<bool> is_prime(maxVal + 1, true);
        is_prime[0] = is_prime[1] = false;
        for (int p = 2; p * p <= maxVal; p++) {
            if (is_prime[p]) {
                for (int i = p * p; i <= maxVal; i += p)
                    is_prime[i] = false;
            }
        }

        // 2. Map value -> indices for quick teleportation
        unordered_map<int, vector<int>> valToIndices;
        for (int i = 0; i < n; i++) {
            valToIndices[nums[i]].push_back(i);
        }

        // 3. BFS
        queue<pair<int, int>> q; // {index, jumps}
        vector<bool> visitedIdx(n, false);
        unordered_set<int> usedPrimes; // Prevent re-processing the same prime

        q.push({0, 0});
        visitedIdx[0] = true;

        while (!q.empty()) {
            auto [currIdx, jumps] = q.front();
            q.pop();

            if (currIdx == n - 1) return jumps;

            // --- Option 1: Adjacent Steps ---
            for (int nextIdx : {currIdx - 1, currIdx + 1}) {
                if (nextIdx >= 0 && nextIdx < n && !visitedIdx[nextIdx]) {
                    visitedIdx[nextIdx] = true;
                    q.push({nextIdx, jumps + 1});
                }
            }

            // --- Option 2: Prime Teleportation ---
            int p = nums[currIdx];
            if (is_prime[p] && usedPrimes.find(p) == usedPrimes.end()) {
                usedPrimes.insert(p);
                // Jump to all indices j where nums[j] is a multiple of p
                for (int multiple = p; multiple <= maxVal; multiple += p) {
                    if (valToIndices.count(multiple)) {
                        for (int targetIdx : valToIndices[multiple]) {
                            if (!visitedIdx[targetIdx]) {
                                visitedIdx[targetIdx] = true;
                                q.push({targetIdx, jumps + 1});
                            }
                        }
                        // Optimization: Once we've visited all indices of this multiple, 
                        // we don't need to check this specific multiple value ever again.
                        valToIndices.erase(multiple);
                    }
                }
            }
        }

        return -1;
    }
};