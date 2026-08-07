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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr) return res;
        map<int,map<int, priority_queue<int, vector<int>, greater<int>>>> mpp;
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root, {0,0}});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int x = p.second.first, y = p.second.second;
            mpp[x][y].push(node->val);
            if(node->left) q.push({node->left,{x-1,y+1}});
            if(node->right) q.push({node->right,{x+1,y+1}});
        }
        for(auto& p : mpp){
            vector<int> col;
            for(auto q : p.second){
                while(!q.second.empty()){
                    col.push_back(q.second.top());
                    q.second.pop();
                }
            }
            res.push_back(col);
        }
        return res;
    }
};