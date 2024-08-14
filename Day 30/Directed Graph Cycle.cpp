/*

https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

*/


// Approach 1 : Using normal dfs
class Solution {
  public:
    
    void dfs(vector<int> adj[], int node, vector<bool> &visited, vector<bool> &visitedPath, bool &ans){
        if(ans) return;
        visited[node] = true;
        visitedPath[node] = true;
        
        for(int i=0; i<adj[node].size(); i++){
            
            if(visitedPath[adj[node][i]]){
                ans = true;
                return;
            }
            
            if(!visited[adj[node][i]])
            dfs(adj,adj[node][i],visited,visitedPath,ans);
            
        }
        
        visitedPath[node] = false;
        
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        
        
        vector<bool> visited(V,0);
        vector<bool> visitedPath(V,0);
        
        bool ans = 0;
        
        for(int i=0; i<V; i++){
            if(!visited[i] && !ans)
            dfs(adj,i,visited,visitedPath,ans);
        }
        
        return ans;
    }
};




// Approach 2 : Using Topological sort
class Solution {
  public:
 
    bool isCyclic(int V, vector<int> adj[]) {
        
        vector<bool> visited(V,0);
        vector<int> indegree(V,0);
        
        
        for(int i=0; i<V; i++){
            for(int j=0; j<adj[i].size(); j++)
            indegree[adj[i][j]]++;
        }
        
        
        queue<int> q;
        for(int i=0; i<V; i++)
        if(indegree[i] == 0){
            q.push(i);
            visited[i] = true;
        }
        
        int count = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            
            for(int i=0; i<adj[node].size(); i++){
                if(visited[adj[node][i]]) continue;
                indegree[adj[node][i]]--;
                if(indegree[adj[node][i]] == 0){
                    q.push(adj[node][i]);
                    visited[adj[node][i]] = true;
                }
            }
        }
        
        return count != V;
        
    }
};
