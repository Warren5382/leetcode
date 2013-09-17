class Solution {
	public:
		int maxProfit(vector<int> &prices) {
			if (prices.size() < 2) return 0;
			int res = 0;
			int start = prices[0];
			for (int i = 1; i < prices.size(); i++) {
				if (prices[i] >= prices[i-1]) continue;

				res += prices[i-1] - start;
				start = prices[i];
			}
			res += *(prices.end()-1) - start;
			return res;
		}
};
