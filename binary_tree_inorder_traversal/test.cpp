class Solution {
	public:
		vector<int> inorderTraversal(TreeNode *root) {
			vector<int> result;
			if (NULL == root)
				return result;
			vector<int> leftResult = inorderTraversal(root->left);
			vector<int> rightResult = inorderTraversal(root->right);
			for( int i = 0 ; i < leftResult.size(); ++i)
				result.push_back(leftResult[i]);
			result.push_back(root->val);
			for( int i = 0 ; i < rightResult.size(); ++i)
				result.push_back(rightResult[i]);
			return result;
		}
};
