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
    TreeNode * ans;
public:
    void DFS(TreeNode* root){
        if(!root) return;
        DFS(root->left);
        root->left = NULL;
        ans->right = root;
        ans = ans->right;
        DFS(root->right);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode * tmp = new TreeNode;
        ans = tmp;
        DFS(root);
        return tmp->right;
    }
};