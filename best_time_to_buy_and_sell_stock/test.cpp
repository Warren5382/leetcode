class Solution {
	public:
		int maxProfit(vector<int> &prices) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			if(prices.size() < 2) return 0;
			int curres = 0;
			int curmin = prices[0];
			for(int i = 0; i < prices.size(); i++) {
				if(curres < prices[i]-curmin) {
					curres = prices[i]-curmin;
				}
				curmin = curmin>prices[i]?prices[i]:curmin;
			}
			return curres;

		}
};
