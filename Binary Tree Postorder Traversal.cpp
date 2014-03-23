/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        post(root, res);
        return res;
    }
    
    void post(TreeNode* node, vector<int> &v) {
        if (node == NULL) return;
        post(node->left, v);
        post(node->right, v);
        v.push_back(node->val);
    }
};