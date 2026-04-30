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
    vector<vector<int>> levelOrderTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();  // ✅ fix here
            vector<int> temp;

            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                temp.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            res.push_back(temp);
        }

        return res;
    }

   public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;

        vector<vector<int>> level = levelOrderTraversal(root);

        for (auto row : level) {
            res.push_back(row[row.size()-1]);
        }

        return res;
    }
};
