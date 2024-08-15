/*

https://www.geeksforgeeks.org/problems/bipartite-graph/1

*/


class Solution {
public:

    void dfs(vector<int>adj[], int node, vector<int> &color, int curr, int prev, bool &ans){
        if(!ans) return; 
        color[node] = curr;
        
        for(int i=0; i<adj[node].size(); i++){
            
            // already colored
            if(color[adj[node][i]] != -1){
                if(curr == color[adj[node][i]]){
                    ans = false;
                    return;
                }
            }
            
            // not colored yet
            else{
                dfs(adj,adj[node][i],color,prev,curr,ans);
            }
        }
    }
    
	bool isBipartite(int V, vector<int>adj[]){

	    vector<int> color(V,-1);
	    bool ans = true;
	    
	    
	    for(int i=0; i<V; i++){
	        if(color[i] == -1 && ans)
	        dfs(adj,i,color,0,1,ans);
	    }
	    
	    return ans;
	}

};
