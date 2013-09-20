class Solution {
	private:
		TreeNode *copyTree(TreeNode *root) {
			if(NULL == root) return NULL;
			TreeNode *croot = new TreeNode(root->val);
			croot->left = copyTree(root->left);
			croot->right = copyTree(root->right);
			return croot;
		}
		vector<TreeNode *> generateTrees(int startval,int endval) {
			vector<TreeNode *> ret;
			if(endval < startval) {
				ret.push_back(NULL);
			}
			else {
				for(int rootval = startval; rootval <= endval; ++rootval) {
					vector<TreeNode*> temp;
					{//push root into ret
						TreeNode *root = new TreeNode(rootval);
						temp.push_back(root);
					}
					//process the left subtrees
					vector<TreeNode*> lefts = generateTrees(startval, rootval - 1);
					int count = temp.size();
					for(int ti = 0; ti < count; ++ti) {
						TreeNode *root = temp[0];
						temp.erase(temp.begin());
						for(int li = 0; li < lefts.size(); ++li) {
							TreeNode* left = lefts[li];
							TreeNode *newroot = copyTree(root);
							newroot->left = left;
							temp.push_back(newroot);
						}
						//if(root) delete root;
					}
					//process the right subtrees
					vector<TreeNode*> rights = generateTrees(rootval + 1, endval);
					count = temp.size();
					for(int ti = 0; ti < count; ++ ti) {
						TreeNode *root = temp[0];
						temp.erase(temp.begin());
						for(int ri = 0; ri < rights.size(); ++ri) {
							TreeNode *copyExpand = copyTree(root);
							copyExpand->right = rights[ri];
							temp.push_back(copyExpand);
						}
						//if(root) delete root;
					}
					for(int i = 0; i < temp.size(); ++i) {
						ret.push_back(temp[i]);
					}
				}
			}
			return ret;
		}
	public:
		vector<TreeNode *> generateTrees(int n) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			return generateTrees(1,n);
		}
};
