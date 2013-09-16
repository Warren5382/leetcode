class Solution {
	public:
		int sumNumbers(TreeNode *root) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			int sum = 0;
			int total = 0;
			total = calcSum(root, sum);
			return total;
		};
		int calcSum(TreeNode *root, int sum) {
			if(root == NULL) {
				return sum;
			}
			sum = 10*sum + root->val;
			int tempsum = 0;
			int leftsum = 0;
			int rightsum = 0;
			leftsum = calcSum(root->left, sum);
			rightsum = calcSum(root->right, sum);
			if(leftsum != sum) tempsum += leftsum;
			if(rightsum != sum) tempsum += rightsum;
			if(tempsum!=0) sum=tempsum;
			return sum;
		};

};
