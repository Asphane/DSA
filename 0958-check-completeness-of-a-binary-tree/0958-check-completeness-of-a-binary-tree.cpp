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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool is_Past_Left_Null = false;

        while(!q.empty()){
            int n = q.size();
            while(n--){
                auto node = q.front();
                q.pop();

                if(node == nullptr){
                    is_Past_Left_Null = true;
                }

                else{
                    if(is_Past_Left_Null == true){
                        return false;
                    }
                    q.push(node->left);
                    q.push(node->right);
                }
            }
        }
        return true;
    }
};