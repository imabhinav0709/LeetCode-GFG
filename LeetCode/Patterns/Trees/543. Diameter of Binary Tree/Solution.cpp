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
    int height(TreeNode* node, int& maxi){
        if(node == NULL) return 0;
        int l = height(node->left, maxi);
        int r = height(node->right, maxi);
        maxi = max(maxi, l+r);
        return 1 + max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = INT_MIN;
        height(root, maxi);
        return maxi;
    }
};