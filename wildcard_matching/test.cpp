class Solution {
	bool isMatch(const char *s, const string &p) {
		for(int i = 0; i < p.size(); ++i) {
			char cs = *(s+i);
			if (cs == '\0') return false;
			char cp = p[i];
			if (cp != '?' && cp != cs) return false;
		}
		return true;
	}
	vector<string> splitPatten(const char *p) {
		vector<string> splitp;
		string seg="";
		int ip = 0;
		while(true) {
			char c = *(p + ip);
			if (c == '\0' || c == '*') {
				//a segment found, if seg.size() > 0
				if(seg.size() > 0) {
					//cout<<seg<<"|";
					splitp.push_back(seg);
					seg="";
				}
			} else {
				seg += c;
			}
			if (c=='\0') break;
			++ip;
		}
		return splitp;
	}
	public:
	bool isMatch(const char *s, const char *p) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		//0.check parameters
		if(s==NULL || p==NULL) return false;
		//1.segment patten by *
		vector<string> splitp = splitPatten(p);
		//2.0.
		if(splitp.size() == 0) {
			//all the chararactors in p is *, or, p is empty
			if(strlen(p) == 0)
				return *s == '\0';
			return true;
		}
		//2.determin if the first seg is fix at front of s and the last seg is fix at the rear of s
		bool fixBegin = false,fixEnd = false;
		{
			if(*p!='*') fixBegin = true;
			if(*(p + strlen(p) - 1) != '*') fixEnd = true;
		}
		//3.go through all the patten's segemnts in p,
		//check them one by one in s,
		//with the consideration of fixBegin and fixEnd
		int si = 0;
		const int lens = strlen(s);
		for(int i = 0; i < splitp.size(); ++i) {
			string &patseg = splitp[i];
			//the last available start index in s
			int lastsi = lens - patseg.size();
			//match is impossible
			if(lastsi < si) return false;
			int ei = lastsi;
			//if this is the first pattern segment and we must match at the beginning of s
			if(i==0 && fixBegin) ei = si;
			//the similiar situation for last pattern segment
			if(i== splitp.size() - 1 && fixEnd) {
				si = lastsi;
				//the segment must from beginning of s and to ending of s.
				if (i==0 && fixBegin && 0!=si) return false;
			}

			bool matched = false;
			for(int iins=si; !matched && iins <= ei; ++iins) {
				matched = isMatch(s + iins,patseg);
				si = iins + patseg.size();
			}
			//there is an mismatch
			if(!matched) return false;
		}
		return true;
	}
};
