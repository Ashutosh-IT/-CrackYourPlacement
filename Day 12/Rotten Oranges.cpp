/*

https://www.geeksforgeeks.org/problems/rotten-oranges2536/1

*/

class Solution 
{
    public:
    int row[4] = {-1,1,0,0};
    int col[4] = {0,0,-1,1};
    
    bool valid(int i, int j, int n, int m){
        return i>=0 && j>=0 && i<n && j<m;
    }
    
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        
        int n=grid.size();
        int m=grid[0].size();
        
        queue<pair<int,int>> q;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2)
                q.push({i,j});
            }
        }
    
        
        vector<vector<bool>> visited(n,vector<bool>(m,0));
        
        int ans = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                
                for(int k=0; k<4; k++){
                    int newR = i+row[k];
                    int newC = j+col[k];
                    
                    if(valid(newR,newC,n,m) && !visited[newR][newC] && grid[newR][newC] == 1){
                        q.push({newR,newC});
                        visited[newR][newC] = true;
                    }
                }
            }
            ans++;
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && !visited[i][j])
                return -1;
            }
        }
        
        return ans == 0 ? 0 :ans-1;
    }
};
