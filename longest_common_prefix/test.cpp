class Solution {
	public:
		string longestCommonPrefix(vector<string> &strs) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			string result;
			char common;
			int curCharIndex = 0;
			for(int istr = 0 ; istr < strs.size() ; ++istr) {
				string &str = strs[istr];
				if(curCharIndex >= str.size())
					return result;
				if(istr == 0 ) {
					common = str[curCharIndex];
				}else if(str[curCharIndex] != common) {
					return result;
				}
				if(istr == strs.size() - 1) {
					result.push_back(common);
					++curCharIndex; 
					istr = -1;
				}
			}
			return result;
		}
};
