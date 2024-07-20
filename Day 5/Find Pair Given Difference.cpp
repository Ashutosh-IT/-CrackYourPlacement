/*

https://www.geeksforgeeks.org/problems/find-pair-given-difference1559/1

*/

class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
        // code here
        
        sort(arr.begin(),arr.end());
        
        int i=0, j=1;
        
        while(j<n){
            
            if(i==j) j++;
            
            if(arr[j]-arr[i] == x)
            return 1;
            
            else if(arr[j]-arr[i] > x) i++;
            
            else j++;
            
        }
        
        return -1;
    }
};
