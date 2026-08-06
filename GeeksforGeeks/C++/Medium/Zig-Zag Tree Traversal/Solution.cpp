/* Structure of Binary Tree Node
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        // code here
        vector<int> res;
        if(root == NULL) return res;
        queue<Node*> q;
        q.push(root);
        bool flag = true;
        while(!q.empty()){
            int len = q.size();
            vector<int> row(len);
            for(int i=0; i<len; i++){
                Node* node = q.front();
                q.pop();
                int ind = (flag) ? i : len-i-1;
                row[ind] = node->data;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            flag = !flag;
            for(int i : row){
                res.push_back(i);
            }
        }
        return res;
    }
};