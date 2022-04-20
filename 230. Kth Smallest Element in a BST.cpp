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
    int cnt = 1, ans = 0;
    void DFS(TreeNode* root, int k){
        if(root == NULL) return;
        DFS(root->left, k);
        if(cnt == k) ans = root->val; 
        ++cnt;
        DFS(root->right, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        DFS(root, k);
        return ans;
    }
};