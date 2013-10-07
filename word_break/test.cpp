class Solution {
	public:
		bool wordBreak(string s, unordered_set<string> &dict) {
			// Note: The Solution object is instantiated only once and is reused by each test case.
			if(dict.count(s) >= 1) {
				return true;
			}
			for(int i = 1; i < s.size(); i++) {
				if(dict.count(s.substr(i)) >= 1) {
					if(wordBreak(s.substr(0, i), dict)) {
						return true;
					}
				} 
			}
			return false;
		}
};
