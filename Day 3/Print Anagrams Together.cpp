/*

https://www.geeksforgeeks.org/problems/print-anagrams-together/1

*/

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& strs) {
        //code here
        
        int n = strs.size();
        vector<vector<string>> ans;
        int index = 0;

        unordered_map<string,int> mp;

        for(int i=0; i<n; i++){
            string temp = strs[i];
            sort(temp.begin(),temp.end());

            if(mp.find(temp) != mp.end())
            ans[mp[temp]].push_back(strs[i]);

            else{
                mp[temp] = index;
                index++;
                ans.push_back({strs[i]});
            }
        }

        return ans;
        
    }
};
