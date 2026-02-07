class Solution {
public:
    void dfs(int m,int n,int i,int j,vector<vector<char>>& board){
        if(i<0||j<0||i>=m||j>=n) return;
        board[i][j] = '#';
        if(i+1<m&&board[i+1][j]=='O') dfs(m,n,i+1,j,board);
        if(i-1>=0&&board[i-1][j]=='O') dfs(m,n,i-1,j,board);
        if(j+1<n&&board[i][j+1]=='O') dfs(m,n,i,j+1,board);
        if(j-1>=0&&board[i][j-1]=='O') dfs(m,n,i,j-1,board);
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>>change(m,vector<bool>(n,true));
        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                board[i][0] = '#';
                dfs(m,n,i,0,board);
            }
            if(board[i][n-1]=='O'){
                board[i][n-1] = '#';
                dfs(m,n,i,n-1,board);
            }
        }
        for(int i=0;i<n;i++){
            if(board[0][i]=='O'){
                board[0][i] = '#';
                dfs(m,n,0,i,board);
            }
            if(board[m-1][i]=='O'){
                board[m-1][i] = '#';
                dfs(m,n,m-1,i,board);
            }
        }
        for(int i=0;i<m;i++){
            for(int j =0;j<n;j++){
                if(board[i][j]=='X') continue;
                else{
                    if(board[i][j]=='#'){
                        board[i][j] = 'O';
                    }
                    else{
                        board[i][j] = 'X';
                    }
                }
            }
        }
    }
};