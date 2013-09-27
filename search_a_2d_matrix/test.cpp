class Solution {
	public:
		int binary_search(vector<vector<int> > &matrix, int m, int n, int value) {
			int left = 0;
			int right = m*n - 1;
			int middle;
			while(left <= right) {
				middle = (left + right)/2;
				if(matrix[middle/n][middle%n] > value) {
					right = middle-1;
				}
				else if(matrix[middle/n][middle%n] < value) {
					left = middle+1;
				}
				else return middle;
			}
			return -1;
		}
		bool searchMatrix(vector<vector<int> > &matrix, int target) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			int m = matrix.size();
			int n = matrix[0].size();
			int ret = binary_search(matrix, m, n, target);
			if(ret == -1) {
				return false;
			}
			else {
				return true;
			}
		}
};
