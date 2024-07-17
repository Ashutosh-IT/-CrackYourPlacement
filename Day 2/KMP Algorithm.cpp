/*

https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

*/

class Solution {
public:

    void findLPS(string &needle, vector<int> &lps){
        int i=0;
        int j=1;

        while(j<needle.size()){
            // match
            if(needle[i] == needle[j]){
                lps[j] = i+1;
                i++;
                j++;
            }

            // not match
            else{
                if(i==0){
                    lps[j] = 0;
                    j++;
                }
                else{
                    i = lps[i-1];
                }
            }
        }
    }

    int strStr(string haystack, string needle) {

        int n = haystack.size();
        int m = needle.size();

        vector<int> lps(m,0);
        findLPS(needle,lps);

        // KMP Algorithm
        int i=0, j=0;

        while(i<n && j<m){
            // match
            if(haystack[i] == needle[j]){
                i++;
                j++;
            }

            // not match
            else{
                if(j==0){
                    i++;
                }
                else{
                    j = lps[j-1];
                }
            }
        }

        if(j==m) return i-j;
        

        return -1;
    }
};
