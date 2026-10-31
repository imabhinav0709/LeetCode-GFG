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
class NodeValue{
    public:
        int minNode;
        int maxNode;
        int maxSum;

        NodeValue(int minNode, int maxNode, int maxSum){
            this->minNode = minNode;
            this->maxNode = maxNode;
            this->maxSum = maxSum;
        }
};
class Solution {
private:
    NodeValue findlargeSum(TreeNode* node, int& ans){
        if(!node) return NodeValue(INT_MAX, INT_MIN, 0);
        
        auto left = findlargeSum(node->left, ans);
        auto right = findlargeSum(node->right, ans);

        if(left.maxNode < node->val && node->val < right.minNode){
            // it is bst
            int sum = left.maxSum + right.maxSum + node->val;
            ans = max(ans, sum);
            return NodeValue(min(left.minNode, node->val), max(right.maxNode, node->val), sum);
        }

        // not a bst
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSum, right.maxSum));
    }
public:
    int maxSumBST(TreeNode* root) {
        int maxSum = 0;
        findlargeSum(root, maxSum);
        return (maxSum >0 ) ? maxSum : 0;
    }
};