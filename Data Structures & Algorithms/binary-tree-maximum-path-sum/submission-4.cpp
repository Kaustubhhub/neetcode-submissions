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
    int dfs(TreeNode* node, int &res){
        if(node == nullptr)return 0;

        int left = max(0,dfs(node->left, res));
        int right = max(0,dfs(node->right, res));

        res = max(res,left + right + node->val);

        return node->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {   
        int res = INT_MIN;

        dfs(root, res);

        return res;
    }
};
