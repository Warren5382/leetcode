class Solution {
	public:
		int reverse(int x) {
			int sign = x < 0? -1: 1;
			int ret = 0;
			x = abs(x);
			while(x > 0)
			{
				ret = ret*10 + x%10;
				x /= 10;
			}
			return sign*ret;
		}
};
