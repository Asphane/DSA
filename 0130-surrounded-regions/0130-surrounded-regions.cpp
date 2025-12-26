class Solution {
public:
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};
    int m, n;

    void dfs(vector<vector<char>>& board, int i, int j){
        board[i][j]='S';

        for(auto &d: directions){
            int new_i=i+d[0];
            int new_j=j+d[1];

            if(new_i>=0 && new_i<m && new_j>=0 && new_j<n && board[new_i][new_j]=='O'){
                dfs(board, new_i, new_j);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        m=board.size();
        n=board[0].size();

        for(int i=0; i<m; i++){
            if(board[i][0]=='O'){
                dfs(board, i, 0);
            }

            if(board[i][n-1]=='O'){
                dfs(board, i, n-1);
            }
        }

        for(int j=0; j<n; j++){
            if(board[0][j]=='O'){
                dfs(board, 0, j);
            }

            if(board[m-1][j]=='O'){
                dfs(board, m-1, j);
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }

                else if(board[i][j]=='S'){
                    board[i][j]='O';
                }
            }
        }
    }
};