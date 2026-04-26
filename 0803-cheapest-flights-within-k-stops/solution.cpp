class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // create adjcency list
        vector<vector<pair<int, int>>> adjList(n);

        for(vector<int> v : flights){
            adjList[v[0]].push_back({v[1], v[2]});
        }

        priority_queue<pair<int , pair<int, int>>, vector<pair<int , pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        pq.push({0, {src, 0}});
        vector<int> dist(n, 1e8);
        dist[src] = 0;

        while(!pq.empty()){
            int stops = pq.top().first;
            int node = pq.top().second.first;
            int cost = pq.top().second.second;

            pq.pop();
            if(stops > k) continue;

            for( pair<int, int> neighbour : adjList[node]){
                if(dist[neighbour.first] > neighbour.second + cost){
                    dist[neighbour.first] = neighbour.second + cost;
                    pq.push({stops + 1, {neighbour.first, neighbour.second + cost }});
                }
            }
        }

        return dist[dst] == 1e8 ? -1 : dist[dst]; 
    }
};
