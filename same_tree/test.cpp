class Solution {
	public:
		bool isSameTree(TreeNode *p, TreeNode *q) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			if(p==NULL&&q==NULL) return true;
			bool ret = judgesame(p, q);
			return ret;
		};
		bool judgesame(TreeNode *p, TreeNode *q) {
			if(p==NULL) {
				if(q==NULL) {
					return true;
				}
				return false;
			}
			else {
				if(q==NULL) {
					return false;
				}
				if(p->val != q->val) {
					return false;
				}
				if(!judgesame(p->left, q->left)) {
					return false;
				}
				if(!judgesame(p->right, q->right)) {
					return false;
				}
				return true;
			}
		};
};
