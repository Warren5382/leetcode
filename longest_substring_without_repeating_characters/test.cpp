class Solution {
	public:
		int lengthOfLongestSubstring(string s) {
			int n = s.length();
			int i = 0;
			int j = 0;
			int maxlen = 0;
			bool exist[256] = {false};
			while(j < n) {
				if(exist[s[j]]) {
					maxlen = max(maxlen, j-i);
					while(s[i] != s[j]) {
						exist[s[i]] = false;
						i++;
					}
					i++;
					j++;
				}
				else {
					exist[s[j]] = true;
					j++;
				}
			}
			maxlen = max(maxlen, n-i);
			return maxlen;
		}
};
