/*

https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

*/

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    
	    int n = matrix.size();
	    
	    
	   // changing all the -1 to large value, so that it will not affect our answer
	    for(int i=0; i<n; i++){
	        for(int j=0; j<n; j++){
	            if(matrix[i][j] == -1)
	            matrix[i][j] = 1e6;
	        }
	    }
	    
	   // take every node as intermediate
	    for(int k=0; k<n; k++){
	       
	       //update value of matrix
	       for(int i=0; i<n; i++){
	           for(int j=0; j<n; j++){
	               matrix[i][j] = min(matrix[i][j],matrix[i][k]+matrix[k][j]);
	           }
	       }
	    }
	    
	   // change again larger value to -1
	    for(int i=0; i<n; i++){
	        for(int j=0; j<n; j++){
	            if(matrix[i][j] == 1e6)
	            matrix[i][j] = -1;
	        }
	    }
	    
	  
	}
};

