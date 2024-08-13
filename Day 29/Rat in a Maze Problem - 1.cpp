/*

https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

*/

class Solution {
  public:
    vector<string> ans;
    
    int row[4] = {1,0,0,-1};
    int col[4] = {0,-1,1,0};
    string dir = "DLRU";
    
    bool valid(int i, int j, int n){
        return i>=0 && j>=0 && i<n  && j<n;
    }
    
    void find(vector<vector<int>> &mat, int i, int j, int n, string &path){
        
        if(i==n-1 && j==n-1){
            ans.push_back(path);
            return;
        }
    
        mat[i][j] = -1;
        for(int k=0; k<4; k++){
            int newR = i+row[k];
            int newC = j+col[k];
            
            if(valid(newR,newC,n) && mat[newR][newC] == 1){
                path.push_back(dir[k]);
                find(mat,newR,newC,n,path);
                path.pop_back();
            }
        }
        
        mat[i][j] = 1;
    }
    
    vector<string> findPath(vector<vector<int>> &mat) {
    
        int n  = mat.size();
        
        if(mat[0][0] == 0 || mat[n-1][n-1] == 0)
        return {"-1"};
        
        string path = "";
        find(mat,0,0,n,path);
        
        return ans;
        
    }
};
