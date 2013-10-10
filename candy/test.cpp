class Solution {
	public:
		int candy(vector<int> &ratings) {
			// Note: The Solution object is instantiated only once and is reused by each test case.
			int length = ratings.size();
			int sum = 0;
			if(length == 0) return 0;
			vector<int> candys(length, 1);
			for(int i = 1; i < length; i++) {
				if(ratings[i] > ratings[i-1]) {
					if(candys[i] <= candys[i-1]) {
						candys[i] = candys[i-1]+1;
					}
				}
			}
			for(int i = length-2; i >= 0; i--) {
				if(ratings[i] > ratings[i+1]) {
					if(candys[i] <= candys[i+1]) {
						candys[i] = candys[i+1]+1;
					}
				}
			}
			for(int i = 0; i < length; i++) {
				sum += candys[i];
			}
			return sum;
		}
};
