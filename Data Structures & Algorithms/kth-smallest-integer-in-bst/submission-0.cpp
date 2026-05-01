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
    void helper(TreeNode* node, int k, int &res, int &curr){
        if(!node)return;

        helper(node->left,k,res,curr);
        curr++;
        if(curr == k){
            res = node->val;
            return;
        }
        helper(node->right,k,res,curr);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        int res = -1, curr = 0;
        helper(root, k, res,curr);
        return res;
    }
};
