class Solution {
	private:
		int _curMax;
		//return the max path ending in root
		//and refresh the _curMax with the path sum that go through from left to root to right child.
		int maxWithRoot(TreeNode *root) {
			if(NULL == root) return 0;
			int leftmax = maxWithRoot(root->left);
			int rightmax = maxWithRoot(root->right);

			//the max from left child to right child, accross from root
			int arcmax = root->val;
			if(leftmax > 0) arcmax += leftmax;
			if(rightmax > 0) arcmax += rightmax;
			if(_curMax < arcmax) _curMax = arcmax;

			//the max that end in root
			int pathmax = root->val;
			int submax = std::max(leftmax,rightmax);
			if(submax > 0) pathmax += submax;
			if(_curMax < pathmax) _curMax = pathmax;

			return pathmax;
		}
	public:
		int maxPathSum(TreeNode *root) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			_curMax = INT_MIN;
			maxWithRoot(root);
			return _curMax;
		}
};
