/*

https://leetcode.com/problems/making-a-large-island/

*/


class Solution {
public:

    int row[4] = {1,-1,0,0};
    int col[4] = {0,0,1,-1};

    bool valid(int i, int j, int n){
        return i>=0 && j>=0 && i<n && j<n;
    }

    void dfs(vector<vector<int>>& grid, int i, int j, int n, int group, int &count){
        count++;
        grid[i][j] = group;

        for(int k=0; k<4; k++){
            int newR = i+row[k];
            int newC = j+col[k];

            if(valid(newR,newC,n) && grid[newR][newC] == 1)
            dfs(grid,newR,newC,n,group,count);
        }

    }

    int largestIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();

        // not starting from 1 to avoid using visited array
        int group = 2, ans = 0;
        unordered_map<int,int> mp;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    int count = 0;
                    dfs(grid,i,j,n,group,count);
                    mp[group] = count;
                    ans = max(ans,count);
                    group++;
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0){
                    unordered_set<int> st;
                    int size = 1;
                    for(int k=0; k<4; k++){
                        int newR = i+row[k];
                        int newC = j+col[k];

                        if(valid(newR,newC,n) && st.find(grid[newR][newC]) == st.end()){
                            st.insert(grid[newR][newC]);
                            size += mp[grid[newR][newC]];
                        }
                    }
                    ans = max(ans,size);
                }
            }
        }

        return ans;
    }
};
