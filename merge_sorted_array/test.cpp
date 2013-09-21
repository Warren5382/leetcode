class Solution {
	public:
		void merge(int A[], int m, int B[], int n) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			int index=m+n-1;
			int aIndex=m-1;
			int bIndex=n-1;
			while(0<=aIndex&&0<=bIndex) {
				if(B[bIndex]>A[aIndex]) {
					A[index--] = B[bIndex--];
				}
				else {
					A[index--] = A[aIndex--];
				}
			}
			while(0 <= aIndex) {
				A[index--]=A[aIndex--];
			}
			while(0 <= bIndex) {
				A[index--]=B[bIndex--];
			}
		}
};
