class Solution {
	public:
		bool isBSTHelp(TreeNode *root, int min, int max) {
			if(root == NULL) return true;
			if(min < root->val && max > root->val) {
				return isBSTHelp(root->left, min, root->val)&&isBSTHelp(root->right, root->val, max);
			}
			else {
				return false;
			}
		}
		bool isValidBST(TreeNode *root) {
			return isBSTHelp(root, INT_MIN, INT_MAX);
		}
};
