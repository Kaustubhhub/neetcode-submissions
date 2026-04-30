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
    vector<vector<int>>levelOrderTraversal(TreeNode* root){
        vector<vector<int>>res;
        if(!root)return res;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            vector<int>temp;
            for(int i=0; i<q.size(); i++){
                temp.push_back(q.front()->val);
                if(q.front()->left)q.push(q.front()->left);
                if(q.front()->right)q.push(q.front()->right);
                q.pop();
            }
            res.push_back(temp);
        }

        return res;
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        if(!root)return res;

        vector<vector<int>>level = levelOrderTraversal(root);

        for(int i=0; i<level.size(); i++){
            for(int j=0; j<level[i].size(); j++){
                cout<<level[i][j]<<" ";
            }
            cout<<"\n";
        }

        for(auto row : level){
            res.push_back(row[0]);
        }

        return res;
    }
};
