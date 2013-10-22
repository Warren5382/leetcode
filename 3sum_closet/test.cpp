class Solution {
	public:
		int threeSumClosest(vector<int> &num, int target) {
			int nSize = num.size();
			assert(nSize > 2);
			sort(num.begin(), num.end());

			int nMin = num[0] + num[1] + num[2];
			int diff = abs(nMin - target);
			for (int i = 0; i < nSize - 2; ++i)
			{
				int l = i + 1;
				int r = nSize - 1;
				int sum = 0;
				while(l < r)
				{
					sum = num [i] + num[l] + num[r];
					if (sum == target)  return sum;
					if (abs(sum - target) < diff)
					{
						nMin = sum;
						diff = abs(sum - target);
					}
					if (sum > target)
						--r;
					else
						++l;
				}
			}
			return nMin;
		}
};
