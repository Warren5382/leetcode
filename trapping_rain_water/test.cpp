class Solution {
	public:
		int trap(int A[], int n) {
			// Note: The Solution object is instantiated only once and is reused by each test case.
			if(n <= 2) return 0;
			int *lmh = new int[n];
			lmh[0] = 0;
			int maxh = A[0];
			for(int i = 1; i < n; i++) {
				lmh[i] = maxh;
				if(maxh < A[i]) maxh = A[i];
			}
			int trapped = 0;
			maxh = A[n-1];
			for(int i = n-2; i > 0; --i) {
				int left = lmh[i];
				int right = maxh;
				int container = min(left, right);
				if(container > A[i]) {
					trapped += container - A[i];
				}
				if(maxh < A[i]) maxh=A[i];
			}
			delete lmh;
			return trapped;
		}
};
