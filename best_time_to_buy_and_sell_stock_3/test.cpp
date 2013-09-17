class Solution {
	public:
		int maxProfit(vector<int> &prices) {
			if (prices.size() < 2) return 0;
			int s = prices.size();
			int *a = new int[s+1];
			int *b = new int[s+1];
			memset(a, 0, 4*s+4);
			memset(b, 0, 4*s+4);

			int curm = prices[0];
			a[0] = 0;
			for (int i = 1; i < s; ++i) {
				a[i] = max(a[i-1], prices[i] - curm);
				curm = min(curm, prices[i]);
			}

			curm = prices[s-1];
			b[s-1] = 0;
			for (int i = s-2; i >=0; --i) {
				b[i] = max(b[i+1], curm - prices[i]);
				curm = max(curm, prices[i]);
			}

			int res = 0;
			for (int i = 0; i < s; i++) {
				res = max(res, a[i] + b[i+1]);
			}

			delete []a;
			delete []b;
			return res;
		}
};
