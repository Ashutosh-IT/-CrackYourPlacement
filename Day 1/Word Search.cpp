/*

https://leetcode.com/problems/word-search/description/

*/

class Solution {
public:

    int row[4] = {0,0,-1,1};
    int col[4] = {1,-1,0,0};

    bool valid(int i, int j, int n, int m){
        return i>=0 && j>=0 && i<n && j<m;
    }

    bool dfs(vector<vector<char>>& board, int n, int m, int i, int j, vector<vector<bool>> &visited, string word, int index){
        visited[i][j] = true;
        bool ans = false;

        if(index==word.size()) return true;

        for(int k=0; k<4; k++){
            int newR = i+row[k];
            int newC = j+col[k];
            if(valid(newR,newC,n,m) && !visited[newR][newC] && board[newR][newC] == word[index]){
                ans = ans || dfs(board,n,m,newR,newC,visited,word,index+1);
            }
        }
        visited[i][j] = false;
        return ans;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == word[0]){
                    if(word.size() == 1) return true;
                    vector<vector<bool>> visited(n,vector<bool>(m,false));
                    if(dfs(board,n,m,i,j,visited,word,1))
                    return true;
                }
            }
        }

        return false;
    }
};
