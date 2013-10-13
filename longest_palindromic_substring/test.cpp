class Solution {
	public:
		string longestPalindrome(string s) {
			string result;
			string s1;
			if (s.length() < 2) return s;
			vector<int> p(s.length() * 2 + 1, 0);
			int pivot = 0, cover = 0;
			s1.push_back('#');
			for (int i = 0;i < s.length();++i) {
				s1.push_back(s[i]);
				s1.push_back('#');
			}
			for (int i = 0;i < s1.length();++i) {
				if (i < cover) {
					if (p[2 * pivot - i] < cover - i)
						p[i] = p[2 * pivot - i];
					else
						p[i] = cover - i;
				} else p[i] = 0;
				while (i - p[i] >= 0 && i + p[i] < s1.length() &&
						s1[i - p[i]] == s1[i + p[i]]) p[i]++;
				p[i]--;
				if (i + p[i] > cover) {
					cover = i + p[i];
					pivot = i;
				}
			}
			int maxlen = 0, maxid = 0;
			for (int i = 0;i < s1.length();++i) {
				if (p[i] > maxlen) {
					maxlen = p[i];
					maxid = i;
				}
			}
			return s.substr((maxid - maxlen)/ 2, maxlen);
		}
};
