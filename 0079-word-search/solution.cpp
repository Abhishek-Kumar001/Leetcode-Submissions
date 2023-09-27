class Solution {
private:
    bool DFS( vector<vector<char>>& board, string word, int i, int  j, int cnt){
        if(cnt == word.size()) return true;

        int m = board.size();
        int n = board[0].size();
        if( i== -1 || i==m || j==-1 || j==n || board[i][j] != word[cnt]){
            return false;
        }       

        char temp = board[i][j];
        board[i][j] ='*';
        bool found = DFS(board,word, i-1, j, cnt+1) || 
                     DFS(board,word, i, j+1, cnt+1) || 
                     DFS(board,word, i+1, j, cnt+1) || 
                     DFS(board,word, i, j-1, cnt+1) ;
        
        board[i][j] = temp;
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        int m = board.size();
        int n = board[0].size();

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == word[0]){
                        bool ans = DFS( board, word, i, j , 0);
                        if( ans) return true;
                }
            }
        }
        return false;
    }
    
};




/*
for(int i=0; i<4; i++){        
            int nrow = row+ drow[i];
            int ncol = col + dcol[i];

            if( nrow >=0 && nrow < m && ncol >=0 && ncol <n){
                if( board[nrow][ncol] == word[cnt]){
                    ans=  DFS(board, word, nrow, ncol, cnt+1);
                   // if(ans) return true;
                }
            }      
}

*/
