/*

https://www.geeksforgeeks.org/problems/alien-dictionary/1

*/


class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        
        vector<int> adj[K];
        vector<int> indegree(K,0);
        
        for(int i=0; i<N-1; i++){
            int j=0;
            while(j<dict[i].size() && j<dict[i+1].size() && (dict[i][j] == dict[i+1][j])) j++;
            if(j == dict[i].size() || j == dict[i+1].size()) continue;
            adj[dict[i][j]-'a'].push_back(dict[i+1][j]-'a');
            indegree[dict[i+1][j]-'a']++;
        }
        
        queue<int> q;
        for(int i=0; i<K; i++)
        if(indegree[i] == 0) q.push(i);
        
        string ans = "";
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node+'a');
            
            for(int i=0; i<adj[node].size(); i++){
                indegree[adj[node][i]]--;
                if(indegree[adj[node][i]] == 0)
                q.push(adj[node][i]);
            }
        }
        
        return ans;
    }
};
