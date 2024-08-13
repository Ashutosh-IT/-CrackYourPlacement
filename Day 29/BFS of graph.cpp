/*

https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

*/


class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        queue<int> q;
        q.push(0);
        
        vector<bool> visited(V,0);
        visited[0] = true;
        
        vector<int> ans;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(int i=0; i<adj[node].size(); i++){
                if(!visited[adj[node][i]]){
                    q.push(adj[node][i]);
                    visited[adj[node][i]] = true;
                }
            }
        }
        
        return ans;
    }
};
