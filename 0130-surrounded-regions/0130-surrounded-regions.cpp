class Solution {
public:

    struct hashPair {
        size_t operator()(const pair<int,int>& p) const {
            return p.first * 31 + p.second;
        }
    };

    void dfs(int i, int j,
             vector<vector<char>>& board,
             unordered_set<pair<int,int>, hashPair>& visited) {

        int n = board.size();
        int m = board[0].size();

        if (i < 0 || j < 0 || i >= n || j >= m) return;
        if (board[i][j] != 'O') return;
        if (visited.count({i,j})) return;

        visited.insert({i,j});

        dfs(i+1, j, board, visited);
        dfs(i-1, j, board, visited);
        dfs(i, j+1, board, visited);
        dfs(i, j-1, board, visited);
    }

    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        unordered_set<pair<int,int>, hashPair> visited;

        // Step 1: Mark all 'O' connected to boundary
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') dfs(i, 0, board, visited);
            if (board[i][m-1] == 'O') dfs(i, m-1, board, visited);
        }
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') dfs(0, j, board, visited);
            if (board[n-1][j] == 'O') dfs(n-1, j, board, visited);
        }

        // Step 2: Flip all 'O' not visited → 'X'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && visited.count({i,j}) == 0) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
