/*

https://www.geeksforgeeks.org/problems/negative-weight-cycle3504/1

*/

class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    
	   // bellman ford - single source shortest path 
	   
	   vector<int> dist(n,1e8);
	   // dist[0] = 0; let 0th node as source
	   
	   
	   // relax all the edges n-1 times
	   for(int j=1; j<n; j++){
	       
	       // relax all edges
	       for(int i=0; i<edges.size(); i++){
	           int u = edges[i][0];
	           int v = edges[i][1];
	           int wt = edges[i][2];
	           
	           if(dist[v] > dist[u]+wt){
	               dist[v] = dist[u]+wt;
	           }
	       }
	   }
	   
	   
	   // to detect cycle - do relaxation one more time to all edges
	   for(int i=0; i<edges.size(); i++){
           int u = edges[i][0];
           int v = edges[i][1];
           int wt = edges[i][2];
           
           
        //   there is a change, so -ve cycle is present
           if(dist[v] > dist[u]+wt){
               return 1;
           }
       }
       
       return 0;
	}
};
