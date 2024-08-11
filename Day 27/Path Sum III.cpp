/*

https://leetcode.com/problems/path-sum-iii/description/

*/

class Solution {
public:

    void find(TreeNode *root, int &ans, long long &sum, int k, unordered_map<long long,int> &mp){
        if(!root) return;

        sum += root->val;
        ans += mp[sum-k];

        mp[sum]++;

        find(root->left,ans,sum,k,mp);
        find(root->right,ans,sum,k,mp);

        mp[sum]--;
        sum -= root->val;
    }

    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long,int> mp;
        mp[0] = 1;
        int ans = 0;
        long long sum = 0;
        find(root,ans,sum,targetSum,mp);
        return ans;
    }
};

  
