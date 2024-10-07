class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n= rooms.size();
        vector<int> visited(n, 0);

        queue<int> q;
        q.push(0);
        visited[0] = 1;

        while(!q.empty()){
            int roomNo = q.front();
            q.pop();

            for(auto it : rooms[roomNo]){
                if(visited[it] == 0){
                    q.push(it);
                    visited[it] = 1;
                }
            }
        }

        for(int  roomNo =0; roomNo<n; roomNo++ ){
            if(visited[roomNo] == 0) return false;
        }
        return true;
    }
};
