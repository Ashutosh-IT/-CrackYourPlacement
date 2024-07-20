/*

https://www.geeksforgeeks.org/problems/counting-sort/0

*/

class Solution{
    public:
    //Function to arrange all letters of a string in lexicographical 
    //order using Counting Sort.
    string countSort(string arr){
        // code here
        vector<int> freq(26,0);
        for(int i=0; i<arr.size(); i++)
        freq[arr[i]-'a']++;
        
        int index=0;
        for(int i=0; i<26; i++){
            if(freq[i] == 0) continue;
            for(int j=0; j<freq[i]; j++)
            arr[index++] = i+'a';
        }
        
        return arr;
    }
};
