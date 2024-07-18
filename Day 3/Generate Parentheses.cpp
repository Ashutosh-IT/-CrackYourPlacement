/*

https://leetcode.com/problems/generate-parentheses/description/

*/

class Solution {
public:

    vector<string> ans;

    void find(int n, string &temp, int c1, int c2){

        if(temp.size()==2*n){
            ans.push_back(temp);
            return;
        }

        if(c1<n){
            temp.push_back('(');
            find(n,temp,c1+1,c2);
            temp.pop_back();
        }

        if(c2<c1){
            temp.push_back(')');
            find(n,temp,c1,c2+1);
            temp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string temp;
        find(n,temp,0,0);
        return ans;
    }
};
