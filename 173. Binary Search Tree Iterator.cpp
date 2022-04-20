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
class BSTIterator {
public:
    stack<TreeNode*> nums;
    BSTIterator(TreeNode* root) {
        TreeNode * curr = root;
        while(curr != NULL){
            nums.push(curr);
            curr = curr->left;
        }
    }
    
    int next() {
        TreeNode* ans = nums.top();
        nums.pop();
        TreeNode * curr = ans->right;
        while(curr != NULL){
            nums.push(curr);
            curr = curr->left;
        }
        return ans->val;
    }
    
    bool hasNext() {
        return nums.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */