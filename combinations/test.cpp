class Solution {
	public:
		vector<vector<int> > combine(int n, int k) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			vector<vector<int>> result;
			if(k>n || n<=0 || k<=0) {
				return result;
			}
			vector<int> index(k);
			for(int i = 0; i < k; i++) {
				index[i] = i+1;
			}
			do {
				result.push_back(index);
				bool carry = false;
				int cur = k-1;
				do {
					if(index[cur] < n-(k-1-cur)) {
						carry = false;
						++index[cur];
						for(int i = 1; i+cur<k; i++) {
							index[i+cur]=index[cur]+i;
						}
					}
					else {
						carry = true;
						if(--cur < 0) {
							return result;
						}
					}
				}while(carry&&cur>=0);
			}while(true);
			return result;
		}
};
