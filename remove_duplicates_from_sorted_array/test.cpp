class Solution {
	public:
		int removeDuplicates(int A[], int n) {
			int start = 0;
			if(n<=1) return n;
			for(int i = 1; i < n; i++) {
				if(A[start] != A[i]) {
					A[start+1] = A[i];
					start++;
				}
			}
			return start+1;
		}
};
