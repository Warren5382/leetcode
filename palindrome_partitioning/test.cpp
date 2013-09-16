class Solution {
	public:
		vector<vector<string>> partition(string s) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			vector<vector<string>> vec;
			vector<int> index;
			if(s.length() == 0)
				return vec;
			index.push_back(-1);
			DFS(s, 0, vec, index);
			return vec;
		}
		void DFS(string& s, int i, vector<vector<string>> &vec, vector<int> &index) {
			if(i == s.length()) {
				vector<string> v;
				int len = index. size();
				for(int k = 0; k < len-1; k++)
					v.push_back(s.substr(index[k]+1, index[k+1]-index[k]));
				vec.push_back(v);
				return;
			}
			for(int j = i; j < s.length(); j++) {
				if(isPalindrome(s, i, j)) {
					index.push_back(j);
					DFS(s, j+1, vec, index);
					index.pop_back();
				}
			}
		}
		bool isPalindrome(string& s, int i, int j) {
			while(i<j) {
				if(s[i++] != s[j--])
					return false;
			}
			return true;
		}
};
