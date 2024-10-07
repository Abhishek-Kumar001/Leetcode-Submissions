class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        //tech dose code approach & code i have just convert his dfs code to bfs
        vector<int> visited(n + 1, 0); // no need of visited 
        vector<int> color(n + 1, -1); //sirf color[] se v ho jata

        // creating a adjlist
        vector<int> adjList[n + 1];
        for (auto it : dislikes) {
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                queue<int> q;
                q.push(i);
                visited[1] = 1;
                color[i] = 1;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (auto it : adjList[node]) {
                        if (visited[it] && color[it] == color[node]) {
                            return false;
                        } else if (visited[it] == 0) {
                            visited[it] = 1;
                            color[it] = 1 - color[node];
                            q.push(it);
                        }
                    }
                }
            }
        }
        return true;
    }
};
