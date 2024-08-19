/*

https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/

*/


class Solution {
public:

    int dijkstra(vector<pair<int,int>> adj[], int source, int n, int limit){
        vector<int> dist(n,INT_MAX);
        dist[source] = 0;

        vector<bool> visited(n,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,source});

        while(!pq.empty()){
            int u = pq.top().second;
            int wt = pq.top().first;
            pq.pop();
            visited[u] = true;

            for(int i=0; i<adj[u].size(); i++){
                int v = adj[u][i].first;
                int dis = adj[u][i].second;

                if(!visited[v] && dist[v] > wt+dis){
                    dist[v] = wt+dis;
                    pq.push({dist[v],v});
                }
            }
        }

        int count = 0;
        for(int i=0; i<n; i++){
            if(source == i) continue;
            if(dist[i] <= limit)
            count++;
        }

        return count;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        // graph ke liye adjacency list bna lo
        vector<pair<int,int>> adj[n];

        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }


        // har node par dijkstra lgao aur ans count kro
        int ans = -1;
        int count = INT_MAX;
        for(int i=0; i<n; i++){
            int num = dijkstra(adj,i,n,distanceThreshold);
            if(num <= count){
                count = num;
                ans = i;
            }
        }

        return ans;
    }
};
