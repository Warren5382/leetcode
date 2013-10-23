/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    bool isBalanced(TreeNode *root, int *depth){
        if(NULL == root){
            *depth = 0;
            return true;
        }
        int left, right;
        if(isBalanced(root->left, &left) && isBalanced(root->right, &right)){
            int diff = left - right;
            if((diff>1) || (diff<-1)){
                return false;
            }
            *depth = 1 + (left > right ? left : right);
            return true;
        }
    }
    
public:
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int depth = 0;
        return isBalanced(root, &depth);
    }
};ß