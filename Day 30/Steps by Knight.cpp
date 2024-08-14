/*

https://www.geeksforgeeks.org/problems/steps-by-knight5927/1

*/



class Solution 
{
    public:
    
    int row[8] = {1,2,-1,-2,1,-1,2,-2};
    int col[8] = {2,1,-2,-1,-2,2,-1,1};
    
    bool valid(int i, int j, int n){
        return i>=0 && i<n && j>=0 && j<n;
    }
    
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    vector<vector<bool>> visited(N,vector<bool>(N,0));
	    queue<pair<pair<int,int>,int>> q;
	    
	    q.push({{KnightPos[0]-1,KnightPos[1]-1},0});
	    
	    while(!q.empty()){
	        
	        int i = q.front().first.first;
	        int j = q.front().first.second;
	        int steps = q.front().second;
	        q.pop();
	        
	        if(i==TargetPos[0]-1 && j==TargetPos[1]-1) return steps;
	        
	        for(int k=0; k<8; k++){
	            int newR = i+row[k];
	            int newC = j+col[k];
	            
	            if(valid(newR,newC,N) && !visited[newR][newC]){
	                q.push({{newR,newC},steps+1});
	                visited[newR][newC] = true;
	            }
	        }
	        
	    }
	    
	    return -1;
	    
	}
};
