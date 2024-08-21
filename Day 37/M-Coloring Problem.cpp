/*

https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1

*/



class Solution{
public:
    
    
    bool find(vector<int> adj[], int node, unordered_map<int,int> &mp, vector<bool> &visited, int m){
        
        // check colors of all its neighbour
        unordered_set<int> st;
        for(int i=0; i<adj[node].size(); i++){
            if(visited[adj[node][i]])
            st.insert(mp[adj[node][i]]);
        }
        
        // jo color neighbour ko nhi diya hua h use use kro
        for(int i=0; i<m; i++){
            
            // mil gya color
            if(st.find(i) == st.end()){
                // color dedo
                mp[node] = i;
                visited[node] = true;
                
                bool ans = true;
                
                // ab neighbours ko color do jinko nhi mila hai
                for(int j=0; j<adj[node].size(); j++){
                    if(!visited[adj[node][j]])
                    ans = ans && find(adj,adj[node][j],mp,visited,m);
                }
                
                // jo color humne diya hai vo thik nhi hai - baaki colors try kro
                if(ans == false){
                    visited[node] = false;
                    mp.erase(node);
                }
                
                // sabhi neighbours ko colors de paye - color thik diya hai
                else{
                    return true;
                }
            }
        }
        
        // agar loop chal gya pura to iska matlab humare paas color khatam hogye hai
        return false;
        
    }
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        
        // convert to adjacency list
        vector<int> adj[n];
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++)
            if(graph[i][j]) adj[i].push_back(j);
        }
        
        unordered_map<int,int> mp;
        vector<bool> visited(n,0);
        
        for(int i=0; i<n; i++){
            if(!visited[i])
            if(find(adj,i,mp,visited,m) == false)
            return false;
        }
        
        
        return true;
        
    }
};
