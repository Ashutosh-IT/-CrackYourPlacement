/*

https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/

*/

class Solution {
public:
    int row[4] = {0,0,-1,1};
    int col[4] = {1,-1,0,0};

    bool valid(int i, int j, int n, int m){
        return i>=0 && j>=0 && i<n && j<m;
    }

    int dfs(vector<vector<int>>& matrix, int i, int j, int n, int m, vector<vector<bool>> &visited, vector<vector<int>> &dp){

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        visited[i][j] = true;
        int ans = 1;

        for(int k=0; k<4; k++){
            int newR = i+row[k];
            int newC = j+col[k];

            if(valid(newR,newC,n,m) && matrix[i][j] < matrix[newR][newC]){
                ans = max(ans,1 + dfs(matrix,newR,newC,n,m,visited,dp));
            }
        }

        return dp[i][j] = ans;

    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n,vector<int>(m,-1));
        vector<vector<bool>> visited(n,vector<bool>(m,0));

        int ans = 1;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++)
            if(!visited[i][j])        
            ans = max(ans,dfs(matrix,i,j,n,m,visited,dp)); 
        }
        return ans;
    }
};
