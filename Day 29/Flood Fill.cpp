/*

https://leetcode.com/problems/flood-fill/description/

*/

class Solution {
public:

    int row[4] = {0,0,-1,1};
    int col[4] = {1,-1,0,0};

    bool valid(int i, int j, int n, int m){
        return i>=0 && j>=0 && i<n && j<m;
    }

    void dfs(vector<vector<int>>& image, int n, int m, int i, int j, int &prev, int &color){
        image[i][j] = color;

        for(int k=0; k<4; k++){
            int newR = i+row[k];
            int newC = j+col[k];

            if(valid(newR,newC,n,m) && image[newR][newC] == prev)
            dfs(image,n,m,newR,newC,prev,color);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        int prev = image[sr][sc];
        if(prev == color) return image;

        dfs(image,n,m,sr,sc,prev,color);
        return image;
    }
};
