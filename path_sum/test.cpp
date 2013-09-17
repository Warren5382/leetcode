class Solution {
	public:
		struct state {
			TreeNode *node;
			int sum;
			state() : node(NULL), sum(0) {};
		};
		bool hasPathSum(TreeNode *root, int sum) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			if(root == NULL) return false;
			queue<state> que;
			state now;
			state next;
			now.node = root;
			now.sum += root->val;
			que.push(now);
			while(!que.empty()) {
				now = que.front();
				if(now.sum == sum &&(now.node->left==NULL && now.node->right==NULL)) {
					return true;
				}
				if(now.node->left != NULL) {
					next.node = now.node->left;
					next.sum = now.node->left->val + now.sum;
					que.push(next);
				}
				if(now.node->right != NULL) {
					next.node = now.node->right;
					next.sum = now.node->right->val + now.sum;
					que.push(next);
				}
				que.pop();
			}
			return false;
		};
};
