class Solution {
	public:
		struct state{
			TreeNode *node;
			int depth;
			state():node(NULL),depth(0) {};
		};
		int minDepth(TreeNode *root) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			if(root==NULL) return 0;
			queue<state> que;
			state now;
			state next;
			now.node = root;
			now.depth = 1;
			que.push(now);
			while(!que.empty()) {
				now = que.front();
				if(now.node->left==NULL&&now.node->right==NULL) {
					return now.depth;
				}
				if(now.node->left!=NULL) {
					next.node = now.node->left;
					next.depth = now.depth+1;
					que.push(next);
				}
				if(now.node->right!=NULL) {
					next.node = now.node->right;
					next.depth = now.depth+1;
					que.push(next);
				}
				que.pop();
			}
			return 0;
		};
};
