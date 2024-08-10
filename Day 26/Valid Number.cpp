/*

https://leetcode.com/problems/valid-number/description/

*/

class Solution {
public:
    bool isNumber(string s) {
        
        bool digit = false, e = false, dot = false;
        int countPlusMinus = 0;

        for(int i=0; i<s.size(); i++){
            if(s[i] >= '0' && s[i] <= '9'){
                digit = true;
            }

            else if(s[i] == '-' || s[i] == '+'){

                if(countPlusMinus == 2) return false;
                if(i>0 && (s[i-1] != 'e' && s[i-1] != 'E')) return false;
                if(i==s.size()-1) return false;

                countPlusMinus++;
            }

            else if(s[i] == '.'){

                if(e || dot) return false;
                if(i==s.size()-1 && !digit) return false;

                dot = true;
            }

            else if(s[i] == 'e' || s[i] == 'E'){
                if(e || !digit) return false;
                if(i==s.size()-1) return false;
                e = true;
            }

            else return false;
        }
        return true;
    }
};
