/*

https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

*/


class Solution {
  public:

    void dfs(vector<int> adj[], int node, vector<bool> &visited, int parent, bool &ans){
        if(ans) return;
        visited[node] = true;
        
        for(int i=0; i<adj[node].size(); i++){
            
            if(parent != adj[node][i] && visited[adj[node][i]]){
                ans = true;
                return;
            }
            
            if(!visited[adj[node][i]])
            dfs(adj,adj[node][i],visited,node,ans);
            
        }
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V,0);
        bool ans = false;
        
        for(int i=0; i<V; i++){
            if(!visited[i] && !ans)
            dfs(adj,i,visited,-1,ans);
        }
        
        return ans;
    }
};
