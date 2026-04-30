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
    void dfs(TreeNode* node, int &goodNodesCount, int &currMax){
        if(!node)return;

        if(node->val >= currMax){
            goodNodesCount++;
            currMax = node->val;
        }

        dfs(node->left, goodNodesCount, currMax);
        dfs(node->right, goodNodesCount, currMax);
    }
    int goodNodes(TreeNode* root) {
        int currMax = INT_MIN;
        int goodNodesCount = 0;

        dfs(root, goodNodesCount, currMax);

        return goodNodesCount;

    }
};
