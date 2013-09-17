class Solution {
	public:
		void flatten(TreeNode *root) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			if(root == NULL) {
				return;
			}
			flatten(root->left);
			flatten(root->right);
			TreeNode *temp = root->right;
			TreeNode *temproot = root;
			root->right = root->left;
			root->left = NULL;
			while(temproot->right != NULL) {
				temproot = temproot->right;
			}
			temproot->right = temp;
		}
};
