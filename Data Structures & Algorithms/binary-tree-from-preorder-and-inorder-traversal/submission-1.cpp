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
    TreeNode* helper(vector<int>& preorder, int &curr,
                     int low, int high,
                     unordered_map<int,int>& mpp) {

        if (low > high) return nullptr;

        int val = preorder[curr];          // ✅ correct source
        TreeNode* node = new TreeNode(val);

        int idx = mpp[val];                // find in inorder
        curr++;                            // move preorder pointer ONCE

        node->left = helper(preorder, curr, low, idx - 1, mpp);
        node->right = helper(preorder, curr, idx + 1, high, mpp);

        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mpp;
        
        for(int i=0; i<inorder.size(); i++){
            mpp[inorder[i]] = i;
        }

        int low = 0, high = preorder.size()-1;
        int curr = 0;
        return helper(preorder,curr, low, high, mpp);
    }
};
