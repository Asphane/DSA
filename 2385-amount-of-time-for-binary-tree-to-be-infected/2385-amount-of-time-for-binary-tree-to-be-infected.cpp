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
    unordered_map<TreeNode*, TreeNode*> parent;
    unordered_set<TreeNode*> visited;

    TreeNode* find(TreeNode* root, int start){
        if(!root) return nullptr;

        if(root->val == start) return root;

        TreeNode* l = find(root->left, start);
            if(l) return l;

        TreeNode* r = find(root->right, start);
        
        return r;
    }

    void findParent(TreeNode* root){
        if(!root) return;

        if(root->left){
            findParent(root->left);
            parent[root->left] = root;
        }

        if(root->right){
            findParent(root->right);
            parent[root->right] = root;
        }
    }

    int solve(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        visited.insert(root);
        int minutes = 0;

        while(!q.empty()){
            int n = q.size();
            while(n--){
                auto node = q.front();
                q.pop();

                if(node->left && !visited.count(node->left)){
                    q.push(node->left);
                    visited.insert(node->left);
                }

                if(node->right && !visited.count(node->right)){
                    q.push(node->right);
                    visited.insert(node->right);
                }

                if(parent.count(node) && !visited.count(parent[node])){
                    q.push(parent[node]);
                    visited.insert(parent[node]);
                }
            }
            minutes++;
        }
        return minutes-1;
    }

    int amountOfTime(TreeNode* root, int start) {
        TreeNode* infected = find(root, start);
        findParent(root);
        return solve(infected);
    }
};