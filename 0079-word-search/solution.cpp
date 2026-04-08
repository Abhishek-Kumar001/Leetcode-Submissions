class Solution {
    bool dfs(int i, int j, int k,int n, int m, vector<vector<char>> &board, string &word, vector<vector<int>> &visited){
        if(k == word.size()) return true;

        visited[i][j] = true;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for(int dir = 0; dir < 4; dir++){
            int nrow = i + drow[dir];
            int ncol = j + dcol[dir];

            if( nrow < n && nrow >= 0 && ncol >= 0 && ncol < m && board[nrow][ncol] == word[k] && visited[nrow][ncol] == 0){
                bool result = dfs(nrow, ncol, k+1, n, m, board, word, visited);
                if(result) return true;
            }
        }
        visited[i][j] = 0;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == word[0]){
                    bool result = dfs(i, j, 1, n, m, board, word, visited);
                    if(result) return true;
                }
            }
        }
        return false;
    }
};
