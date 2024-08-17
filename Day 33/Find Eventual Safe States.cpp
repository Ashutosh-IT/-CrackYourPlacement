/*

https://leetcode.com/problems/find-eventual-safe-states/description/

*/

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adjRev(n);
        vector<int> indegree(n,0);

        for(int i=0; i<n; i++){
            for(int j=0; j<graph[i].size(); j++){
                adjRev[graph[i][j]].push_back(i);
                indegree[i]++;
            }
        }

        vector<int> ans;

        // apply kahn's algorithm
        queue<int> q;
        for(int i=0; i<n; i++)
        if(indegree[i] == 0) q.push(i);

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(int i=0; i<adjRev[node].size(); i++){
                indegree[adjRev[node][i]]--;
                if(indegree[adjRev[node][i]] == 0) 
                q.push(adjRev[node][i]);
            }
        }

        sort(ans.begin(),ans.end());
        return ans;
    }
};
