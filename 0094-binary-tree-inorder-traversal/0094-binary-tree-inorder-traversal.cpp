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

    // void inorder(TreeNode* root, vector<int> &res){
    //     if(root==nullptr) return;

    //     inorder(root->left, res);
    //     res.push_back(root->val);
    //     inorder(root->right, res);
    // }

    vector<int> inorderTraversal(TreeNode* root) {
        // vector<int> ans;
        // inorder(root, ans);

        // return ans;

        // ----------------------------
        // Morris

        vector<int> res;
        TreeNode* curr = root;

        while(curr){
            if(!curr->left){
                res.push_back(curr->val);
                curr = curr->right;
            }   
            
            else{
                TreeNode* leftChild = curr->left;

                while(leftChild->right){
                    leftChild = leftChild->right;
                }
                leftChild->right = curr;
                TreeNode* temp = curr;
                curr = curr->left;
                temp->left = nullptr;
            }
        }
        return res;
    }
};