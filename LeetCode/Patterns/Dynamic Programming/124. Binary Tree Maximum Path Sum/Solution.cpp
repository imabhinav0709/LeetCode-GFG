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
    int findmax(TreeNode* node, int& maxi){
        if(node == NULL) return 0;
        int maxl = max(0, findmax(node->left, maxi));
        int maxr = max(0, findmax(node->right, maxi));
        maxi = max(maxi, maxl+maxr+node->val);
        return node->val + max(maxl, maxr);
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        findmax(root, maxi);
        return maxi;
    }
};