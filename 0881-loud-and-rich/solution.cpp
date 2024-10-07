class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        // CHATGPT CODE AND EXPLANATION
        int n = quiet.size();
        
        // Step 1: Create an adjacency list and indegree array
        vector<vector<int>> adjList(n);
        vector<int> indegree(n, 0);
        
        for (auto& pair : richer) {
            adjList[pair[0]].push_back(pair[1]);
            indegree[pair[1]]++;
        }
        
        // Step 2: Initialize the answer array where each person is quietest for themselves
        vector<int> answer(n);
        for (int i = 0; i < n; ++i) {
            answer[i] = i;
        }
        
        // Step 3: Topological Sort using BFS
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        while (!q.empty()) {
            int person = q.front();
            q.pop();
            
            // For each person who is poorer than the current person
            for (int poorer : adjList[person]) {
                // Update the quieter person for 'poorer'
                if (quiet[answer[person]] < quiet[answer[poorer]]) {
                    answer[poorer] = answer[person];
                }
                // Decrease the indegree and if it's zero, add it to the queue
                if (--indegree[poorer] == 0) {
                    q.push(poorer);
                }
            }
        }
        
        return answer;
    }
};

