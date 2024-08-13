/*

https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

*/


class Solution {
  public:
  
    void dfs(int node, vector<int> adj[], vector<bool> &visited, vector<int> &ans){
        visited[node] = true;
        ans.push_back(node);
        
        for(int i=0; i<adj[node].size(); i++){
            if(!visited[adj[node][i]])
            dfs(adj[node][i],adj,visited,ans);
        }
        
    }
    
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        
        vector<int> ans;
        vector<bool> visited(V,0);
        
        dfs(0,adj,visited,ans);
        return ans;
    }
};
