class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>  > pq;
        int n=matrix.size();
        
        int i=0;
        while( i<n){
            pq.push({matrix[i][0],{i,0}});
            i++;
        }
     
        int cnt =0;
        while( !pq.empty()){
            int data = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;

            pq.pop();

            cnt++;
            if(cnt == k) return data;

            if( col+1 < n)
               pq.push({matrix[row][col+1],{row,col+1}});
        }
        return -1; // this is not going to execute
    }
};
