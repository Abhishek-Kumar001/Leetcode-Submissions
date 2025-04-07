class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adjList(numCourses);

        for(auto it : prerequisites){
            int u = it[0];
            int v = it[1];

            adjList[v].push_back(u);
            indegree[u]++;
        }


        queue<int>  q;
        for(int i=0; i<indegree.size(); i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        int cnt=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;

            for(auto it: adjList[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        return cnt == numCourses;
    }
};
