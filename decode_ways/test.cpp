class Solution {
	public:
		int numDecodings(string s) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			if(s.size() == 0) {
				return 0;
			}
			vector<int> ways(s.size()+2, 1);
			for(int i = s.size()-1; i >= 0; i--) {
				if(s[i] == '0') {
					ways[i] = 0;
				}
				else {
					ways[i] = ways[i+1];
				}
				if(i+1 < s.size() && (s[i]=='1'||(s[i]=='2'&&s[i+1]<='6'))) {
					ways[i] += ways[i+2];
				}
			}
			return ways[0];
		}
};
