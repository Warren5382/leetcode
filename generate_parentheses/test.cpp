class Solution {
	public:
		void DFS(int depth, int maxdepth, int leftnum, int leftnumtotal, string str, vector<string> &ret) {
			if(leftnumtotal*2 > maxdepth) {
				return;
			}
			if(depth == maxdepth) {
				ret.push_back(str);
				return;
			}
			DFS(depth+1, maxdepth, leftnum+1, leftnumtotal+1, str+'(', ret);
			if(leftnum>0) {
				DFS(depth+1, maxdepth, leftnum-1, leftnumtotal, str+')', ret);
			}
		}
		vector<string> generateParenthesis(int n) {
			vector<string> ret;
			string str = "";
			DFS(0, 2*n, 0, 0, str, ret);
			return ret;

		}
};
