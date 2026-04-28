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
private:
    vector<int>dfs(TreeNode* node){
        if(node == nullptr)return {1,0};

        vector<int>left = dfs(node->left);
        vector<int>right = dfs(node->right);

        if(abs(left[1]-right[1]) > 1 || !left[0] || !right[0])return {0,max(left[1],right[1]) + 1};

        return {1,max(left[1],right[1]) + 1};
    }
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root)[0] == 1;
    }
};
