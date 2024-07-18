/*

https://leetcode.com/problems/reverse-words-in-a-string/

*/

class Solution {
public:
    string reverseWords(string s) {
        
        stringstream ss(s);

        string ans = "", word;

        while(ss >> word)
        ans = word + " " + ans;

        ans.pop_back();
        return ans;
      
    }
};
