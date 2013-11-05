class Solution {
	public:
		int removeDuplicates(int A[], int n) {
			if (n <= 2) return n;

			int cur = 1;
			for (int i = 2; i < n; ++i) {
				if (!(A[i] == A[cur] && A[i] == A[cur - 1]))
					A[++cur] = A[i];
			}

			return cur + 1;
		}
		/                                                                                 };
