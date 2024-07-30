/*

https://www.geeksforgeeks.org/problems/the-celebrity-problem/1

*/

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int N) {
        // code here
        
        int cel = 0;
        
        for(int i=1; i<N; i++){
            if(M[cel][i] == M[i][cel]){
                i++;
                if(i==N) return -1;
                cel = i;
            }
            else if(M[cel][i])
            cel = i;
        }
        
        for(int j=0; j<N; j++)
        if(M[cel][j]) return -1;
        
        for(int i=0; i<N; i++)
        if(i!=cel && M[i][cel]==0) return -1;
             
        return cel;
        
    }
};
