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
        int maxSize;

        NodeValue(int minNode, int maxNode, int maxSize){
            this->minNode = minNode;
            this->maxNode = maxNode;
            this->maxSize = maxSize;
        }
};
class Solution {
private:
    NodeValue findlargeSum(TreeNode* node){
        if(!node) return NodeValue(INT_MAX, INT_MIN, 0);
        
        auto left = findlargeSum(node->left);
        auto right = findlargeSum(node->right);

        if(left.maxNode < node->val && node->val < right.minNode){
            // it is bst
            return NodeValue(min(left.minNode, node->val), max(right.maxNode, node->val), left.maxSize + right.maxSize + node->val);
        }

        // not a bst
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }
public:
    int maxSumBST(TreeNode* root) {
        int maxSum = findlargeSum(root).maxSize;
        return (maxSum >0 ) ? maxSum : 0;
    }
};