class Solution {
	public:
		bool isScramble(string s1, string s2) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			if(s1.size() != s2.size()) return false;
			if(s1 == s2) return true;
			string ts1 = s1,ts2 = s2;
			sort(ts1.begin(), ts1.end());
			sort(ts2.begin(), ts2.end());
			if(ts1 != ts2) return false;
			for(int isep = 1; isep < s1.size(); ++ isep) {
				//seporate s1 as [0,isep - 1],[isep, s1.size() - 1]
				string seg11 = s1.substr(0,isep);
				string seg12 = s1.substr(isep);
				{//see if forward order is ok
					string seg21 = s2.substr(0,isep);
					string seg22 = s2.substr(isep);
					if(isScramble(seg11,seg21) && isScramble(seg12,seg22)) return true;
				}
				{//see if reverse order is ok
					string seg21 = s2.substr(s2.size() - isep);
					string seg22 = s2.substr(0,s2.size() - isep);
					if(isScramble(seg11,seg21) && isScramble(seg12,seg22)) return true;
				}
			}
			return false;
		}
};
