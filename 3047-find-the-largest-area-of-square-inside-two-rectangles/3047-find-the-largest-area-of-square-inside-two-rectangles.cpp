class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        long long ans = 0;
        int n = bottomLeft.size();
        
        // Nested loop to check EVERY pair (i, j)
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                // Rectangle i
                int x1 = bottomLeft[i][0], y1 = bottomLeft[i][1];
                int x2 = topRight[i][0],   y2 = topRight[i][1];
                
                // Rectangle j (not just i+1)
                int x3 = bottomLeft[j][0], y3 = bottomLeft[j][1];
                int x4 = topRight[j][0],   y4 = topRight[j][1];

                // Correct intersection boundaries
                int fx1 = max(x1, x3);
                int fx2 = min(x2, x4);
                int fy1 = max(y1, y3);
                int fy2 = min(y2, y4);

                // If they overlap, width and height must be positive
                if(fx1 < fx2 && fy1 < fy2) {
                    long long width = fx2 - fx1;
                    long long height = fy2 - fy1;
                    long long side = min(width, height);
                    ans = max(ans, side * side);
                }
            }
        }
        return ans;
    }
};