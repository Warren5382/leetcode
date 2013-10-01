class Solution {
	public:
		vector<int> plusOne(vector<int> &digits) {
			int overflow = 1;
			for(int i = digits.size() - 1; i >= 0; --i) {
				int dsum = digits[i] + overflow;
				overflow = dsum / 10;
				digits[i] = dsum % 10;
			}
			if(overflow) {
				digits.insert(digits.begin(),1);
			}
			return digits;
		}
};
