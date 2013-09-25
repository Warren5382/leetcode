class Solution {
	private:
		int DP[1000][1000];
	public:
		int maximalRectangle(vector<vector<char> > &matrix) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			for(int i = 0; i < matrix.size(); i++) {
				DP[i][0] = matrix[i][0]=='1'?1:0;
			}
			for(int i = 0; i < matrix.size(); i++) {
				for(int j = 1; j < matrix[i].size(); j++) {
					DP[i][j]=matrix[i][j]=='1'?DP[i][j-1]+1:0;
				}
			}

			int ret = 0;
			for(int i = 0; i < matrix.size(); i++) {
				for(int j = 0; j < matrix[i].size(); j++) {
					int k = i;
					int width = INT_MAX;
					while(k>=0) {
						if(DP[k][j]==0) {
							break;
						}
						width = min(width, DP[k][j]);
						ret = max(ret, width*(i-k+1));
						k--;
					}
				}
			}
			return ret;

		}
};
