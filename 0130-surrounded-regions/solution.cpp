class Solution {
    void dfs(int row, int col, vector<vector<char>> &board, vector<vector<int>> &visited, int n, int m){
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        
        for(int i=0; i<=3; i++){
            int nrow = drow[i] + row;
            int ncol = dcol[i] + col;
            if(nrow <n-1 && nrow >0 && ncol <m-1 && ncol >0 && board[nrow][ncol] == 'O' && visited[nrow][ncol] == 0){
                visited[nrow][ncol] = 1;
                dfs(nrow, ncol, board, visited, n, m);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if((i == 0 || i == n-1 || j == 0 || j == m-1) && board[i][j] == 'O'){
                    // cout<<i<<', '<<j<<'    ';
                    visited[i][j] = 1;
                    dfs(i, j, board, visited, n, m);
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'O' && visited[i][j] == false) 
                    board[i][j] = 'X';
            }
        }
    }
};
