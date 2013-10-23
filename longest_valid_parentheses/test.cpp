class Solution {
	public:
		int longestValidParentheses(string s) {
			int len = s.length();
			int maxlen = 0;
			vector<int> DP(len, 0);
			for(int i = len-2; i>=0; i--) {
				if(s[i]=='(') {
					int j = i+1 + DP[i+1];
					if(s[j]==')'&&j<len) {
						DP[i] = DP[i+1]+2;
						int k = 0;
						if(j+1 < len) {
							DP[i] += DP[j+1];
						}
					}
					maxlen = max(maxlen, DP[i]);
				}
			}
			return maxlen;
		}
};
