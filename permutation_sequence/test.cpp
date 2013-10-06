class Solution {
	public:
		string getPermutation(int n, int k) {
			char *arr = new char[n];
			int pro = 1;
			for(int i = 0 ; i < n; ++i) {
				arr[i] = '1' + i;
				pro *= (i + 1);
			}
			k = k - 1;
			k %= pro;
			pro /= n;//pro = 1 * 2 * ... * (n-1)
			for(int i = 0 ; i < n-1; ++i) {
				//for index i
				int selectI = k / pro;
				k = k % pro;
				pro /= (n - i - 1);
				int temp = arr[selectI + i];
				for(int j = selectI; j > 0; --j)
					arr[i + j] = arr[i + j - 1];
				arr[i] = temp;
			}
			return string(arr, arr + n);
		}
};
