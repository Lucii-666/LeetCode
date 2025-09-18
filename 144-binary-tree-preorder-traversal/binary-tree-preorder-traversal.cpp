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
    vector<int> result;
    void pre(TreeNode *Node){
        if(!Node)return;
        result.push_back(Node->val);
        pre(Node->left);
        pre(Node->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        pre(root);
        return result;
    }
};