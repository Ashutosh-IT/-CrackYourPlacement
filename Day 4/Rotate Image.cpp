/*

https://leetcode.com/problems/rotate-image/description/

*/

class Solution {
public:

    void reverse(vector<vector<int>>& matrix, int n, int j){
        
        int s=0;
        int e=n-1;

        while(s<e)
        swap(matrix[s++][j],matrix[e--][j]);

    }

    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();

        for(int j=0; j<n; j++)
        reverse(matrix,n,j);

        for(int i=0; i<n; i++)
        for(int j=0; j<i; j++)
        swap(matrix[i][j],matrix[j][i]);

        
    }
};
