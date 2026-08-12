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
    void dfs(TreeNode* node, string& cur, int& res){
        if(!node) return;
        cur += to_string(node->val);
        if(!node->left && !node->right) res += stoi(cur);
        else{
            dfs(node->left,cur,res);
            dfs(node->right,cur,res);
        }
        cur.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        int res=0;
        if(!root) return res;
        string cur;
        dfs(root,cur,res);
        return res;
    }
};