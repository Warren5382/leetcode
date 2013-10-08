class Solution {
	public:
		vector<int> searchRange(int A[], int n, int target) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			vector<int> result(2,-1);
			if(0 == n) return result;
			if(A[0] > target) return result;
			if(A[n-1] < target) return result;
			int i = 0,j = n-1;
			int ti = -1;
			while(i <= j) {
				int mid = (i+j) / 2;
				int midval = A[mid];
				if(target == midval) {
					ti = mid;
					break;
				} else if (target < midval)
					j = mid - 1;
				else
					i = mid + 1;
			}
			if(ti == -1) return result;//target not found
			int si = 0, sj = ti - 1;
			while(si <= sj) {
				int mid = (si + sj) / 2;
				int midval = A[mid];
				if(target == midval) {
					sj = mid - 1;
				} else {
					si = mid + 1;
				}
			}
			//at last si will equal to sj, mid == si == sj, if midval == target, sj will be 1 position before target, else sj is some time before the final test to be 1 postion before target. so, over all, sj will be 1 position before target after the loop break.
			result[0] = sj + 1;
			int ei = ti + 1, ej = n - 1;
			while(ei <= ej) {
				int mid = (ei + ej) / 2;
				int midval = A[mid];
				if(target == midval)
					ei = mid + 1;
				else
					ej = mid - 1;
			}
			result[1] = ei - 1;
			return result;
		}
};
