class Solution {
	unordered_map<int,int> reverse_idx;
	public:
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		reverse_idx.clear();
		for(int i=0;i<inorder.size();++i){
			reverse_idx.insert(make_pair(inorder[i],i));
		}
		return buildTreeAux(preorder,0,0,inorder.size());
	}
	TreeNode * buildTreeAux(vector<int> &preorder,int pre_idx,int inorder_start,int n){
		if(n==0 || pre_idx==preorder.size()) return NULL;
		int root_val=preorder[pre_idx];
		int root_idx=reverse_idx[root_val];
		TreeNode *root=new TreeNode(root_val);
		int n_left = root_idx-inorder_start;
		root->left=buildTreeAux(preorder,pre_idx+1,inorder_start,n_left);
		root->right=buildTreeAux(preorder,pre_idx+n_left+1,root_idx+1,n-n_left-1);
		return root;
	}
};
