class Solution {
	public:
		string minWindow(string S, string T) {
			if(S.size() == 0 || T.size() == 0)  return "";

			int tc[256];//target count in T
			for(int i = 0; i < 256; ++i) tc[i] = 0;
			for(int i = 0 ; i< T.size(); ++i) ++tc[T[i]];
			int totalCount = T.size();//this count down to 0, then the match is possible

			int firstI[256];//first loc on specific char in T
			for(int i = 0 ; i< 256; ++i) firstI[i] = -1;

			int count[256];//current count for each char in T
			for(int i = 0 ; i < 256; ++i) count[i] = 0;

			int *nextSI = new int[S.size()];
			{
				int last[256];
				for(int i = 0 ; i < 256; ++i) last[i] = -1;
				for(int i = S.size() - 1; i >= 0; --i) {
					char si = S[i];
					nextSI[i] = last[si];
					last[si] = i;
				}
			}

			int minI = -1;
			int minL = S.size() + 1;
			for(int i = 0 ; i < S.size(); ++i) {
				char si = S[i];
				if(tc[si] == 0)//this char is irrelavent
					continue;
				if(count[si] < tc[si]) {//the count of this char is not match target yet
					++count[si];
					--totalCount;
					if(count[si] == 1) {//record the first appearance of this char
						firstI[si] = i;
					}
				} else {//there is more si in T, remove the first record one
					firstI[si] = nextSI[firstI[si]];
				}
				//there will be a match
				if(totalCount == 0) {
					int minFirstI = S.size();
					for(int ti = 0; ti < 256; ++ ti) {
						if(tc[ti] == 0) continue;
						int firstIndex = firstI[ti];
						if (firstIndex == -1) {
							minFirstI = S.size();
							break;
						}
						if(firstIndex < minFirstI) minFirstI = firstIndex;
					}
					if(minFirstI < S.size()){
						int len = i - minFirstI + 1;
						if(len < minL) {
							minL = len;
							minI = minFirstI;
						}
					}
				}
			}
			if(minI == -1) return "";
			return S.substr(minI,minL);
		}
};
