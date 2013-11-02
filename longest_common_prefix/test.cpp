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

class Solution {
	public:
		bool isEqual(vector<string> &strs, int index, int start, int end) {
			if(end < start) return true;
			if(end == start) {
				if(strs[start].size() > index) return true;
				else return false;
			}
			int mid = (start + end) / 2;
			bool lEqual = isEqual(strs, index, start, mid);
			bool rEqual = isEqual(strs, index, mid + 1, end);
			if(!lEqual || !rEqual) return false;
			if(index > strs[start].size()) return false;
			if(index > strs[end].size()) return false;
			if(strs[start][index] != strs[end][index]) return false;
			return true;
		}
		string longestCommonPrefix(vector<string> &strs) {
			// Note: The Solution object is instantiated only once and is reused by each test case.
			string res;
			size_t vSize = strs.size();
			if(0 == vSize) return res;
			if(1 == vSize) return strs[0];

			int len = 0;
			while(isEqual(strs, len, 0, vSize - 1)) {
				len ++;
			}
			res = strs[0].substr(0, len);
			return res;
		}
};
