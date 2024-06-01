class Solution {
    bool  dfs(int row , int col, vector<vector<bool>> &visited, vector<vector<char>>& grid,string                                                               word,int i, int n, int m ){
        
        visited[row][col] = true;
       
        // base case 
        if( i == word.size()){
            return true;
        }
        
        int drow[] = {0, +1, 0, -1};
        int dcol[] = {+1, 0, -1, 0};
        
        for (int k = 0; k < 4; k++) {  // name it k not i b/c we have use i already in parameter
            int nrow = row + drow[k];
            int ncol = col + dcol[k];
            
            if( nrow>=0 && nrow <n && ncol>=0 && ncol<m && !visited[nrow][ncol] && grid[nrow]                                    [ncol] == word[i]){
                bool result = dfs(nrow, ncol, visited, grid, word, i+1, n, m);
                if( result ) return true;
            }
     
        }
        visited[row][col] = false;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n= board.size(), m = board[0].size();
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if( visited[i][j]== false && board[i][j] == word[0]){
                    cnt++;
                    bool result =  dfs(i, j, visited, board, word, 1, n, m);
                    if( result) return true;
                }
            }
      
        }
        return false;
    }
};
