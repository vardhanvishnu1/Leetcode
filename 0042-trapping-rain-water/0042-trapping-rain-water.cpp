class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 2) return 0;

        vector<int> leftMax(n), rightMax(n);

        // 1. Fill Prefix Max (Highest bar to the left)
        leftMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }

        // 2. Fill Suffix Max (Highest bar to the right)
        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }

        // 3. Calculate water
        int totalWater = 0;
        for (int i = 0; i < n; i++) {
            // Water level is determined by the shorter of the two peak walls
            int waterLevel = min(leftMax[i], rightMax[i]);
            totalWater += waterLevel - height[i];
        }

        return totalWater;
    }
};