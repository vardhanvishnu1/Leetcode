#include <vector>
#include <set>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Use a set to handle uniqueness automatically
        set<int> uniqueSums;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                // Case 1: The "size 0" rhombus (just the single cell)
                uniqueSums.insert(grid[i][j]);

                // Case 2: Rhombuses with radius k >= 1
                for (int k = 1; ; k++) {
                    int r_bottom = i + 2 * k;
                    int c_left = j - k;
                    int c_right = j + k;

                    // If any corner is out of bounds, no more rhombuses can be centered here
                    if (r_bottom >= m || c_left < 0 || c_right >= n) break;

                    int sum = 0;
                    
                    // The "Walker" t moves along the 4 edges of size k
                    for (int t = 0; t < k; t++) {
                        sum += grid[i + t][j + t];             // Top -> Right
                        sum += grid[i + k + t][j + k - t];     // Right -> Bottom
                        sum += grid[i + 2 * k - t][j - t];     // Bottom -> Left
                        sum += grid[i + k - t][j - k + t];     // Left -> Top
                    }
                    uniqueSums.insert(sum);
                }
            }
        }

        // Move unique sums into a Max Heap (priority_queue)
        priority_queue<int> maxHeap(uniqueSums.begin(), uniqueSums.end());

        vector<int> ans;
        // Extract up to 3 biggest elements
        while (!maxHeap.empty() && ans.size() < 3) {
            ans.push_back(maxHeap.top());
            maxHeap.pop();
        }

        return ans;
    }
};