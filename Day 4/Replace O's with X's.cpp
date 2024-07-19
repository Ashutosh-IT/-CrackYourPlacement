/*

https://www.geeksforgeeks.org/problems/replace-os-with-xs0052/1

*/


class Solution{
public:

    int row[4] = {-1,1,0,0};
    int col[4] = {0,0,-1,1};
    
    bool valid(int i, int j, int n, int m){
        return i>=0 && j>=0 && i<n && j<m;
    }
    
    void dfs(vector<vector<char>> &mat, int n, int m, int i, int j, vector<vector<bool>> &visited){
        
        visited[i][j] = true;
        
        for(int k=0; k<4; k++){
            
            int newR = i+row[k];
            int newC = j+col[k];
            
            if(valid(newR,newC,n,m) && !visited[newR][newC] && mat[newR][newC] == 'O')
            dfs(mat,n,m,newR,newC,visited);
            
        }
        
    }
    
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        
        for(int i=0; i<n; i++){
            
            if(mat[i][0] == 'O' && !visited[i][0])
            dfs(mat,n,m,i,0,visited);
            
            if(mat[i][m-1] == 'O' && !visited[i][m-1])
            dfs(mat,n,m,i,m-1,visited);
            
        }
        
        for(int j=0; j<m; j++){
            
            if(mat[0][j] == 'O' && !visited[0][j])
            dfs(mat,n,m,0,j,visited);
            
            if(mat[n-1][j] == 'O' && !visited[n-1][j])
            dfs(mat,n,m,n-1,j,visited);
            
        }
        
        for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        if(mat[i][j] == 'O' && !visited[i][j])
        mat[i][j] = 'X';
        
        return mat;
        
        
    }
};
