class Solution {
	public:
		int maxSubArray(int A[], int n) {
			// Note: The Solution object is instantiated only once and is reused by each test case.
			int max = -100000;
			int sum = 0;
			for(int i = 0; i < n; i++) {
				sum += A[i];
				if(sum > max) max = sum;
				if(sum < 0) sum = 0;
			}
			return max;
		}
};
