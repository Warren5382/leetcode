class Solution {
	public:
		bool isChar(char &c) {
			if(c>='a'&&c<='z') {
				return true;
			}
			if(c>='A'&&c<='Z') {
				c += 'a'-'A';
				return true;
			}
			if(c>='0'&&c<='9') {
				return true;
			}
			return false;
		};
		bool isPalindrome(string s) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			int i = 0;
			int j = s.length()-1;
			if(j < 0) return true;
			if(j == 0) return true;
			while(i < j) {
				if(!isChar(s[j])) {
					j--;
					continue;
				}
				if(!isChar(s[i])) {
					i++;
					continue;
				}
				if(s[i]!=s[j]) {
					return false;
				}
				i++;
				j--;
			}
			return true;

		}
};
