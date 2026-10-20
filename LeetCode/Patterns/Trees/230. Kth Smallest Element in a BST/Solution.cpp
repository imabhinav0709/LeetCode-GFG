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
    void inorder(TreeNode* root, int k, int& cnt, int& ans){
        if(!root || cnt > k) return;
        inorder(root->left, k, cnt, ans);
        if(cnt > k) return;
        if(cnt == k){
            ans = root->val;
            cnt++;
            return;
        }
        cnt++;
        inorder(root->right, k, cnt, ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;
        if(k == 0) return 0;
        int cnt=1, ans=0;
        inorder(root, k, cnt, ans);
        return ans;
    }
};