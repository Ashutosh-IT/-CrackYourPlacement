/*

https://leetcode.com/problems/shortest-bridge/description/

*/

class Solution {
public:

    int row[4] = {0,0,-1,1};
    int col[4] = {1,-1,0,0};

    bool valid(int i, int j, int n){
        return i>=0 && j>=0 && i<n && j<n;
    }

    void dfs(vector<vector<int>> &grid, int n, int i, int j, vector<vector<bool>> &visited){
        visited[i][j] = true;
        grid[i][j] = 2;

        for(int k=0; k<4; k++){
            int newR = i+row[k];
            int newC = j+col[k];

            if(valid(newR,newC,n) && !visited[newR][newC] && grid[newR][newC] == 1)
            dfs(grid,n,newR,newC,visited);
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n,vector<bool>(n,false));

        bool found = false;
        for(int i=0; i<n && !found; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    dfs(grid,n,i,j,visited);
                    found = true;
                    break;
                }
            }
        }

        queue<pair<pair<int,int>,int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2)
                q.push({{i,j},0});
            }
        }


        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int dis = q.front().second;
            q.pop();

            for(int k=0; k<4; k++){
                int newR = i+row[k];
                int newC = j+col[k];

                if(valid(newR,newC,n) && !visited[newR][newC]){
                    if(grid[newR][newC] == 1)
                    return dis;
                    else{
                        q.push({{newR,newC},dis+1});
                        visited[newR][newC] = true;
                    }
                }
            }
        }

        return -1;
    }
};
