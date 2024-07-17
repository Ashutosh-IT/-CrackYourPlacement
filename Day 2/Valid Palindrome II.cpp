/*

https://leetcode.com/problems/valid-palindrome-ii/description/

*/

class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size();

        int i=0;
        int j=n-1;

        while(i<j && s[i] == s[j]){
            i++;
            j--;
        }

        if(i>=j) return true;

        int x=i;
        int y=j-1;

        while(x<y && s[x] == s[y]){
            x++;
            y--;
        }

        if(x>=y) return true;

        x=i+1;
        y=j;

        while(x<y && s[x] == s[y]){
            x++;
            y--;
        }

        if(x>=y) return true;

        return false;

    }
};
