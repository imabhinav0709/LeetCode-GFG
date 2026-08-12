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
    void dfs(TreeNode* node, string& cur, vector<string>& res){
        if(!node) return;
        string val = (cur.empty()) ? to_string(node->val) : "->"+to_string(node->val);
        cur += val;
        if(!node->left && !node->right) res.push_back(cur);
        else{
            dfs(node->left,cur,res);
            dfs(node->right,cur,res);
        }
        cur.erase(cur.size()-val.size());
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(!root) return res;
        string cur;
        dfs(root,cur,res);
        return res;
    }
};