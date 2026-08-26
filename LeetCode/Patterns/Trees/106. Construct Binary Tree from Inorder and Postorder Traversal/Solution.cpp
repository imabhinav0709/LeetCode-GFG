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
    TreeNode* build(vector<int>& in, int is, int ie, vector<int>& post, int ps, int pe, unordered_map<int,int>& inmap){
        if(is > ie || ps > pe) return NULL;
        TreeNode* root = new TreeNode(post[pe]);
        int ir = inmap[root->val];
        int nl = ir-is;
        root->left = build(in, is, ir-1, post, ps, ps+nl-1, inmap);
        root->right = build(in, ir+1, ie, post, ps+nl, pe-1, inmap);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> inmap;
        int n = inorder.size();
        for(int i=0; i<n; i++) inmap[inorder[i]]=i;
        TreeNode* root = build(inorder, 0, n-1, postorder, 0, n-1, inmap);
        return root;
    }
};