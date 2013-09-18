class Solution {
	public:
		bool isSymmetric(TreeNode *left, TreeNode *right) {
			if(left == NULL) {
				return right == NULL;
			} else {
				if (right == NULL)
					return false;
				else {
					if(left->val != right->val) {
						return false;
					}
					if(!isSymmetric(left->right,right->left)) {
						return false;
					}
					if(!isSymmetric(left->left, right->right)) {
						return false;
					}
					return true;
				}
			}
		}
		bool isSymmetric(TreeNode *root) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			if(NULL == root) return true;
			return isSymmetric(root->left,root->right);
		}
};
