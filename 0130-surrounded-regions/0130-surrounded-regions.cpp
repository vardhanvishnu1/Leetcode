class Solution {
public:
void solve(int m,int n,int i,int j,vector<vector<char>>& board){
    if(i<0||j<0||i>=m||j>=n||board[i][j]=='X'||board[i][j]=='_') return;
    board[i][j] = '_';
    solve(m,n,i+1,j,board);solve(m,n,i,j+1,board);
    solve(m,n,i-1,j,board);solve(m,n,i,j-1,board);
}
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<n;i++){
            if(board[0][i]=='O') solve(m,n,0,i,board);
            if(board[m-1][i]=='O') solve(m,n,m-1,i,board);
        }
        for(int i=0;i<m;i++){
            if(board[i][0]=='O') solve(m,n,i,0,board);
            if(board[i][n-1]=='O') solve(m,n,i,n-1,board);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='_') board[i][j] = 'O';
                else{board[i][j]='X';}
            }
        }
    }
};