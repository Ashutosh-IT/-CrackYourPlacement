/*

https://leetcode.com/problems/add-binary/description/

*/

class Solution {
public:
    string addBinary(string a, string b) {

        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());

        string ans = "";
        bool carry = false;

        int i=0, j=0;

        while(i<a.size() && j<b.size()){

            int sum = a[i]-'0' + b[i]-'0';

            if(sum == 0){
                if(carry){
                    ans.push_back('1');
                    carry = 0;
                }
                else{
                    ans.push_back('0');
                }
            }

            else if(sum == 1){
                if(carry) ans.push_back('0');
                else ans.push_back('1');
            }

            else{
                if(carry) ans.push_back('1');
                else{
                    ans.push_back('0');
                    carry = 1;
                }
            }

            i++;
            j++;

        }


        while(i<a.size()){
            if(a[i] == '0'){
                if(carry){
                    ans.push_back('1');
                    carry = 0;
                }
                else ans.push_back('0');
            }
            else{
                if(carry) ans.push_back('0');
                else ans.push_back('1');
            }
            i++;
        }

        while(j<b.size()){
            if(b[j] == '0'){
                if(carry){
                    ans.push_back('1');
                    carry = 0;
                }
                else ans.push_back('0');
            }
            else{
                if(carry) ans.push_back('0');
                else ans.push_back('1');
            }
            j++;
        }

        if(carry) ans.push_back('1');

        reverse(ans.begin(),ans.end());
        return ans;
    }
};
