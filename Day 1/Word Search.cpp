/*

https://leetcode.com/problems/word-search/description/

*/

class Solution {
public:

    int row[4] = {-1,1,0,0};
    int col[4] = {0,0,-1,1};
    
    bool valid(int i, int j, int n, int m){
        return i>=0 && i<n && j>=0 && j<m;
    }
    
    void dfs(vector<vector<char>>& board, int n, int m, int i, int j, bool &ans, int index, string word){
        if(ans) return;
        if(index==word.size()-1){
            ans=true;
            return;
        }
        
        char temp = board[i][j];
        board[i][j] = '#';
        
        for(int k=0; k<4; k++){
            int newR = i+row[k];
            int newC = j+col[k];
            if(valid(newR,newC,n,m) && board[newR][newC]==word[index+1]){
                dfs(board,n,m,newR,newC,ans,index+1,word);
            }
        }
        
        board[i][j] = temp;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        // Code here
        int n=board.size();
        int m=board[0].size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]==word[0]){
                    bool ans = false;
                    dfs(board,n,m,i,j,ans,0,word);
                    if(ans) return true;
                }
            }
        }
        
        return false;
    }
};

