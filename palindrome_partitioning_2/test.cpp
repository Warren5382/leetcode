class Solution {
	public:
		int minCut(string s) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			int len = s.size();
			if(len < 2) return 0;
			bool isP[len][len];
			int DP[len+1];
			for(int i = 0; i <= len; i++) {
				DP[i] = len-i;
			}
			for(int i = 0; i < len; i++) 
				for(int j = 0; j < len; j++) {
					isP[i][j] = false;
				}
			for(int i = len-1; i >= 0; i--) {
				for(int j = i; j < len; j++) {
					if(s[i] == s[j] && (j-i < 2 || isP[i+1][j-1])) {
						isP[i][j] = true;
						DP[i] = min(DP[i], DP[j+1]+1);
					}
				}
			}
			return DP[0]-1;

		}
};
