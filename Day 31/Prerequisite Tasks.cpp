/*

https://www.geeksforgeeks.org/problems/prerequisite-tasks/1

*/

class Solution {
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    
	    vector<int> adj[N];
	    vector<int> indegree(N,0);
	    
	    for(int i=0; i<P; i++){
	        adj[prerequisites[i].second].push_back(prerequisites[i].first);
	        indegree[prerequisites[i].first]++;
	    }
	    
	    queue<int> q;
	      
	    for(int i=0; i<N; i++)
	    if(indegree[i] == 0) q.push(i);
	       
	    
	    int count = 0;
	    
	    while(!q.empty()){
	        int node = q.front();
	        count++;
	        q.pop();
	        
	        for(int i=0; i<adj[node].size(); i++){
	            indegree[adj[node][i]]--;
	            if(indegree[adj[node][i]] == 0)
	            q.push(adj[node][i]);
	        }
	    }
	    
	    return count == N;
	    
	}
};
