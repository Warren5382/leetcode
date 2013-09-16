class Solution {
	public:
		int longestConsecutive(vector<int> &num) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			vector<int>::iterator it = num.begin();
			map<int, bool> hashtable;
			for(; it != num.end(); it++) {
				hashtable[*it] = false;
			}
			int targetinter = 0;
			int result = 1;
			it = num.begin();
			map<int, bool>::iterator tableit;
			for(; it != num.end(); it++) {
				int longest = 1;
				targetinter = *it;
				while(1) {
					targetinter++;
					tableit = hashtable.find(targetinter);
					if (tableit->second == false && tableit != hashtable.end()) {
						longest++;
						tableit->second = true;
					}
					else {
						break;
					}
				}
				targetinter = *it;
				while(1) {
					targetinter--;
					tableit = hashtable.find(targetinter);
					if (tableit->second == false && tableit != hashtable.end()) {
						longest++;
						tableit->second = true;
					}
					else {
						break;
					}
				}
				if (result < longest) {
					result = longest;
				}
			}
			return result;
		}
};
