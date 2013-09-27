class Solution {
	public:
		inline void swap(int &a, int &b){
			int temp = a;
			a = b;
			b = temp;
		}
		void sortColors(int A[], int n) {
			if(n <= 1) return;
			int i = 0,j = n-1;
			int cur = i;
			while(cur <= j) {
				if(A[cur] == 0) {
					if(cur > i) {
						swap(A[i++],A[cur]);
					} else {
						++cur;
						++i;
					}
				} else if (A[cur] == 2) {
					if(cur < j)
						swap(A[j--],A[cur]);
					else 
						return;
				} else 
					++cur;
			}
		}
};
