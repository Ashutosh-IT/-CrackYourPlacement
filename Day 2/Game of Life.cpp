/*

https://leetcode.com/problems/game-of-life/description/

*/

class Solution {
public:

    int row[8] = {-1,1,0,0,-1,-1,1,1};
    int col[8] = {0,0,-1,1,-1,1,-1,1};

    bool valid(int i, int j, int n, int m){
        return i>=0 && j>=0 && i<n && j<m;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int count = 0;
                for(int k=0; k<8; k++){
                    int newR = i+row[k];
                    int newC = j+col[k];
                    if(valid(newR,newC,n,m) && (board[newR][newC] == 1 || board[newR][newC] == 3))
                    count++;
                }
                if(board[i][j] == 1 && (count < 2 || count > 3)) board[i][j] = 3;
                else if(board[i][j] == 0 && count == 3) board[i][j] = 2;
            }
        }

        // 0-1 == 2
        // 1-0 == 3

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 2) board[i][j] = 1;
                if(board[i][j] == 3) board[i][j] = 0;
            }
        }
    }
};
