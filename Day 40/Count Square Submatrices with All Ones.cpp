/*

https://leetcode.com/problems/count-square-submatrices-with-all-ones/description/

*/

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int l=min(n,m);
        int dp[n][m][l+1];

        int count = 0;


        // single side 
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 1){
                    dp[i][j][1] = 1;
                    count++;
                }
                else dp[i][j][1] = 0;
            }
        }

        // double side
        for(int i=0; i<n-1; i++){
            for(int j=0; j<m-1; j++){
                if(dp[i][j][1] && dp[i][j+1][1] && dp[i+1][j][1] && dp[i+1][j+1][1]){
                    dp[i][j][2] = 1;
                    count++;
                }
                else dp[i][j][2] = 0;
            }
        }

        int length = 3;
        while(length <= l){
            for(int i=0; i<=n-length; i++){
                for(int j=0; j<=m-length; j++){
                    if(dp[i][j][length-1] && dp[i][j+1][length-1] && dp[i+1][j][length-1] && dp[i+1][j+1][length-1]){
                        dp[i][j][length] = 1;
                        count++;
                    }
                    else dp[i][j][length] = 0;
                }
            }

            length++;
        }

        return count;
    }
};
