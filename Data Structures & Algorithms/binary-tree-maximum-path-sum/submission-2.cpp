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
    int maxPathSum(TreeNode* root) {
        if (!root) return -1001;
        
        int l = maxPathSum(root->left);
        int r = maxPathSum(root->right);

        return max(l, max(r, max(r + root->val, max(l + root->val, max(root->val,r + l + root->val)))));
    }
};
