class Solution {
	public:
		int numDistinct(string S, string T) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			if(S.size() < T.size()) return 0;
			if(T.size() == 0) return 0;
			vector<vector<int>> DP(S.size(), vector<int>(T.size(), 0));
			DP[0][0] = (S[0]==T[0]?1:0);
			for(int is = 1; is < S.size(); is++) {
				DP[is][0] = DP[is-1][0];
				if(S[is] == T[0]) {
					DP[is][0]++;
				}
			}
			for(int it = 1; it < T.size(); it++) {
				DP[it][it] = (S[it]==T[it]?DP[it-1][it-1]:0);
				for(int is = it+1; is < S.size(); is++) {
					DP[is][it] = DP[is-1][it];
					if(S[is]==T[it]) {
						DP[is][it] += DP[is-1][it-1];
					}
				}
			}
			return DP[S.size()-1][T.size()-1];
		}
};
