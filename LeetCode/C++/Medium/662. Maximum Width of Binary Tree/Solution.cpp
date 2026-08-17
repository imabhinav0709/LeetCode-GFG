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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int ans=0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            long len = q.size();
            long mmin = q.front().second;
            long first,last;
            for(lio i=0; i<len; i++){
                int curId = q.front().second - mmin;
                TreeNode* node = q.front().first;
                q.pop();
                if(i==0) first = curId;
                if(i==len-1) last = curId;
                if(node->left) q.push({node->left,curId*2+1});
                if(node->right) q.push({node->right,curId*2+2});
            }
            ans = max(ans, last-first+1);
        }
        return ans;
    }
};