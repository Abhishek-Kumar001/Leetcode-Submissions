class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> grid = image;
        vector<vector<int>> visited( m, vector<int>(n, 0));

        queue<pair<int, int>> q;
        q.push( {sr, sc});
        visited[sr][sc] = 1;
        
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        int startColor = grid[sr][sc];
        while( !q.empty() ){
           int row = q.front().first;
           int col = q.front().second;

           grid[row][col] = color;
           q.pop();
           for(int i=0; i<4; i++){
               int drow = row + delRow[i];
               int dcol = col + delCol[i];

               if( drow>=0  && drow<m && dcol>=0 && dcol<n  && visited[drow][dcol]== 0 && 
                                                            grid[drow][dcol] == startColor){
                                                            
                   visited[drow][dcol] = 1;
                   q.push( {drow, dcol} );
               }
           }

        }
        return grid;
    }
};
