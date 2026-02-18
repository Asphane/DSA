/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, map<int, int> &mp, int height){
        queue<pair<TreeNode*, int>> q;
        q.push({root, height});

        while(!q.empty()){
            int n = q.size();
            int sum = 0;
            while(n--){
                auto node = q.front().first;
                int level = q.front().second;
                q.pop();

                mp[level] += node->val;

                if(node->left) q.push({node->left, level+1});
                if(node->right) q.push({node->right, level+1});
            }
        }
    }

    int maxLevelSum(TreeNode* root) {
        map<int, int> mp;
        solve(root, mp, 1);
        int max_sum = INT_MIN;
        int ans = 1;

        for(auto &it: mp){
            if(it.second > max_sum){
                max_sum = it.second;
                ans = it.first;
            }
        }
        return ans;
    }
};