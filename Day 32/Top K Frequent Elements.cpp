/*

https://leetcode.com/problems/top-k-frequent-elements/description/

*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;

        for(int i=0; i<n; i++)
        mp[nums[i]]++;

        vector<int> ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        for(auto it=mp.begin(); it != mp.end(); it++){
            pair<int,int> p = *it;
            if(pq.size() < k) pq.push({p.second,p.first});
            else{
                if(p.second > pq.top().first){
                    pq.pop();
                    pq.push({p.second,p.first});
                }
            }
        }

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
