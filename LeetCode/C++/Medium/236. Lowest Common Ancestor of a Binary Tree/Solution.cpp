/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root==p || root==q) return root;
        TreeNode* lef = lowestCommonAncestor(root->left,p,q);
        TreeNode* rig = lowestCommonAncestor(root->right,p,q);
        if(!lef) return rig;
        else if(!rig) return lef;
        else return root;
    }
};