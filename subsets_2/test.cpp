class Solution {
	public:
		vector<vector<int> > subsetsWithDup(vector<int> &S) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			vector<vector<int>> result;
			if(S.size() < 1) {
				return result;
			}
			sort(S.begin(), S.end());
			vector<bool> pres(S.size(), false);
			while(true) {
				//1. output current
				{
					vector<int> item;
					for(int i = 0; i < pres.size(); i++) {
						if(pres[i]) {
							item.push_back(S[i]);
						}
					}
					result.push_back(item);
				}
				//2. pregress
				bool overflow = true;
				for(int i =0; overflow&&i<pres.size(); i++) {
					overflow = overflow && pres[i];
					pres[i] = !pres[i];
					if(pres[i]==true) {
						for(int j = i-1; j>=0&&S[j]==S[i]; j--) {
							pres[j]=true;
						}
					}
				}
				if(overflow) break;
			}
			return result;
		}
};
