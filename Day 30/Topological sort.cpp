/*

https://www.geeksforgeeks.org/problems/topological-sort/1

*/


// Approach 1 : using kahn's algorithm (bfs technique)
class Solution
{
	public:
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> ans;
	    
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
	    
	    
	    while(!q.empty() && ans.size() != V){
	        int node = q.front();
	        q.pop();
	        ans.push_back(node);
	        
	        for(int i=0; i<adj[node].size(); i++){
	            if(visited[adj[node][i]]) continue;
	            indegree[adj[node][i]]--;
	            if(indegree[adj[node][i]] == 0){
	                q.push(adj[node][i]);
	                visited[adj[node][i]] = true;
	            }
	        }
	    }
	    
	    return ans;
	    
	}
};



// Approach 2 : using stack (dfs technique)
class Solution
{
	public:
	
	void dfs(vector<int> adj[], int node, stack<int> &st, vector<bool> &visited){
	    visited[node] = true;
	    
	    for(int i=0; i<adj[node].size(); i++){
	        if(!visited[adj[node][i]])
	        dfs(adj,adj[node][i],st,visited);
	    }
	    
	    st.push(node);
	} 
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    stack<int> st;
	    vector<bool> visited(V,0);
	    
	    for(int i=0; i<V; i++)
	    if(!visited[i])
	    dfs(adj,i,st,visited);
	    
	    vector<int> ans;
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
};
