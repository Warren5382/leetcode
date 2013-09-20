class Solution {
	public:
		int numTrees(int n) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			if(n <= 1) return n;
			//ways[i] rep. the number of ways with i nodes
			int *ways = new int[n + 1];
			ways[0] = 1;
			ways[1] = 1;
			for(int i = 2 ; i <= n; ++i) {
				ways[i] = 0;
				for(int left = 0; left < i; ++ left) {
					//with number of left noeds in the left sub-tree
					int lways = ways[left];
					int rways = ways[i - left - 1];
					ways[i] += lways * rways;
				}
			}
			int ret = ways[n];
			delete [] ways;
			return ret;
		}
};
