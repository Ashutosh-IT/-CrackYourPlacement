/*

https://leetcode.com/problems/backspace-string-compare/

*/


class Solution {
public:
    bool backspaceCompare(string s, string t) {

        int i = 0;
        for(int j=0; j<s.size(); j++){

            if(s[j] != '#') s[i++] = s[j];
            else i--;
            if(i<0) i=0;

        }

        int i2 = 0;
        for(int j=0; j<t.size(); j++){

            if(t[j] != '#') t[i2++] = t[j];
            else i2--;
            if(i2<0) i2=0;

        }

        if(i != i2) return false;

        for(int j=0; j<i; j++)
        if(s[j] != t[j]) return false;

        return true;

    }
};
