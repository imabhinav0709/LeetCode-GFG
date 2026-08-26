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
    int findLeft(TreeNode* node){
        int h=0;
        while(node){
            h++;
            node=node->left;
        }
        return h;
    }
    int findRight(TreeNode* node){
        int h=0;
        while(node){
            h++;
            node=node->right;
        }
        return h;
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int l = findLeft(root);
        int r = findRight(root);
        if(l == r) return (1<<l) -1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};