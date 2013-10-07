class Solution {
	public:
		int jump(int A[], int n) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			int minstep = 0;
			int ldist = 0;
			int hdist = 0;
			if (n == 1) return 0;
			while(ldist <= hdist) {
				++minstep;
				int lasthdist = hdist;
				for(int i = ldist; i <= lasthdist; ++i) {
					int possibledist = i + A[i];
					if (possibledist >= n-1)
						return minstep;
					if (possibledist > hdist) {
						hdist = possibledist;
					}
				}
				ldist = lasthdist + 1;
			}
			return 0;
		}
};
