class Solution {
public:
    int solve(int turn, vector<int>& piles, int i, int j, vector<vector<vector<int>>>& dp) {
        if (i > j) return 0;
        
        // Use turn & 1 cleanly
        int turnIdx = turn & 1;
        if (dp[i][j][turnIdx] != -1) return dp[i][j][turnIdx];
        
        int result = 0;
        if (turnIdx == 1) {
            // Alice's turn: She wants to MAXIMIZE her score.
            // She gets the stone she picks + whatever she accumulates next.
            int pickLeft = piles[i] + solve(turn + 1, piles, i + 1, j, dp);
            int pickRight = piles[j] + solve(turn + 1, piles, i, j - 1, dp);
            result = max(pickLeft, pickRight);
        } else {
            // Bob's turn: He wants to MINIMIZE Alice's score.
            // He takes a stone (Alice gets 0 points for it) and leaves Alice the worst outcome.
            int pickLeft = solve(turn + 1, piles, i + 1, j, dp);
            int pickRight = solve(turn + 1, piles, i, j - 1, dp);
            result = min(pickLeft, pickRight);
        }
        
        return dp[i][j][turnIdx] = result;
    }
    
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int total = accumulate(piles.begin(), piles.end(), 0);
        
        // dp[i][j][2] works perfectly now
        //  Correct nesting structure
vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
        
        int aliceScore = solve(1, piles, 0, n - 1, dp);
        return aliceScore > (total - aliceScore);
    }
};