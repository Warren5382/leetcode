class Solution {
	public:
		vector<vector<int> > pathSum(TreeNode *root, int sum) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			vector<vector<int>> result;
			vector<int> oneloop;
			int cursum = 0;
			if(root == NULL) return result;
			cursum = root->val;
			oneloop.push_back(root->val);
			DFS(root, sum, cursum, result, oneloop);
			return result;
		};
		void DFS(TreeNode *root, int sum, int cursum, vector<vector<int>> &result, vector<int> &oneloop) {
			if(cursum == sum &&(root->left==NULL&&root->right==NULL)) {
				result.push_back(oneloop);
			}
			if(root->left != NULL) {
				cursum += root->left->val;
				oneloop.push_back(root->left->val);
				DFS(root->left, sum, cursum, result, oneloop);
				oneloop.erase(oneloop.end()-1);
				cursum -= root->left->val;
			}
			if(root->right != NULL) {
				cursum += root->right->val;
				oneloop.push_back(root->right->val);
				DFS(root->right, sum, cursum, result, oneloop);
				oneloop.erase(oneloop.end()-1);
				cursum -= root->right->val;
			}
		}
};
