class Solution {
	public:
		vector<int> grayCode(int n) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			vector<int> result;
			result.push_back(0);
			for (int i=0; i<n; i++) {
				int highbit = 1<<i;
				int len = result.size();
				for(int i=len-1; i>=0; i--) {
					result.push_back(highbit+result[i]);
				}
			}
			return result;
		}
};
