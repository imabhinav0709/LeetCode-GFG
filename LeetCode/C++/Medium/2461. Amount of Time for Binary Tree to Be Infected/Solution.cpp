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
private:
    int findTime(TreeNode* target, unordered_map<TreeNode*,TreeNode*>& mpp){
        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> vis;
        q.push(target);
        vis[target]=true;
        int time=0;
        while(!q.empty()){
            bool f1 = false;
            int len=q.size();
            while(len--){
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !vis[node->left]){
                    vis[node->left] = true;
                    q.push(node->left);
                    f1=true;
                } if(node->right && !vis[node->right]){
                    vis[node->right] = true;
                    q.push(node->right);
                    f1=true;
                } if(mpp[node] && !vis[mpp[node]]){
                    vis[mpp[node]] = true;
                    q.push(mpp[node]);
                    f1=true;
                }
            }
            if(f1) time++;
        }
        return time;
    }
    TreeNode* mapParent(TreeNode* root, unordered_map<TreeNode*,TreeNode*>& mpp, int start){
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* res;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->val == start) res = node;
            if(node->left){
                mpp[node->left] = node;
                q.push(node->left);
            } if(node->right){
                mpp[node->right] = node;
                q.push(node->right);
            }
        }
        return res;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        if(!root) return 0;
        unordered_map<TreeNode*,TreeNode*> mpp;
        TreeNode* target = mapParent(root, mpp, start);
        if(!target) return 0;
        int time = findTime(target, mpp);
        return time;
    }
};