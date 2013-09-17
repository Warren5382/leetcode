class Solution {
	public:
		TreeLinkNode* tryconnect(TreeLinkNode* node) {
			if(node == NULL) {
				return NULL;
			}
			TreeLinkNode* leftroot = tryconnect(node->left);
			TreeLinkNode* rightroot = tryconnect(node->right);
			while(leftroot!=NULL && rightroot!=NULL) {
				leftroot->next = rightroot;
				leftroot = leftroot->right;
				rightroot = rightroot->left;
			}

			return node;
		}
		void connect(TreeLinkNode *root) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			tryconnect(root);
		}
};
