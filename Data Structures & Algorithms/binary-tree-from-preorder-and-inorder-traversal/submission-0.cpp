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
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, unordered_map<int,int>&mpp, int &curr, int low, int high){
        if(low == high){
            return new TreeNode(inorder[low]);
        }
        if(low > high){
            curr--;
            return nullptr;
        }

        int idx = mpp[preorder[curr]];
        TreeNode* node = new TreeNode(preorder[curr]);
        curr++;
        node->left = helper(preorder, inorder, mpp, curr, low, idx-1);
        curr++;
        node->right = helper(preorder, inorder, mpp, curr, idx+1, high);

        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mpp;
        
        for(int i=0; i<inorder.size(); i++){
            mpp[inorder[i]] = i;
        }

        int low = 0, high = preorder.size()-1;
        int curr = 0;
        return helper(preorder, inorder, mpp, curr, low, high);
    }
};
