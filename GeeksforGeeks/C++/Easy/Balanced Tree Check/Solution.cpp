/* Structure of binary tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    int height(Node* node){
        if(node == NULL) return 0;
        int l = height(node->left);
        if(l == -1) return -1;
        int r = height(node->right);
        if(r == -1) return -1;
        if(abs(l-r) > 1) return -1;
        return 1 + max(l,r);
    }
    bool isBalanced(Node* root) {
        // code here
        return (height(root) != -1);
    }
};