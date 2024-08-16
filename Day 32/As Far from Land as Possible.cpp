/*

https://leetcode.com/problems/as-far-from-land-as-possible/description/

*/

class Solution {
public:

    int row[4] = {0,0,-1,1};
    int col[4] = {1,-1,0,0};

    bool valid(int i, int j, int n){
        return i>=0 && j>=0 && i<n && j<n;
    }

    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();

        int count0 = 0, count1 = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                count1 += grid[i][j] == 1;
                count0 += grid[i][j] == 0;
            }
        }

        if(count0 == 0 || count1 == 0) return -1;

        vector<vector<bool>> visited(n,vector<bool>(n,0));
        queue<pair<pair<int,int>,int>> q;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1)
                q.push({{i,j},0});
            }
        }

        int ans = 0;
        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int dis = q.front().second;
            q.pop();
            ans = max(ans,dis);


            for(int k=0; k<4; k++){
                int newR = i+row[k];
                int newC = j+col[k];

                if(valid(newR,newC,n) && grid[newR][newC] == 0){
                    grid[newR][newC] = 1; // mark as visited
                    q.push({{newR,newC},dis+1});
                }
            }
        }

        return ans;
    }
};
