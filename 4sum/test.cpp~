class Solution {
	public:
		vector<vector<int> > fourSum(vector<int> &num, int target) {
			vector<vector<int> > result;
			if(num.size() < 4)
				return result;

			sort(num.begin(),num.end());
			int lastVi = num[0] - 1;
			for(int i = 0 ; i < num.size() - 3; ++i)
			{
				int vi = num[i];
				if(vi == lastVi)
					continue;
				lastVi = vi;

				int lastVj = num[i+1] - 1;
				for( int j = i + 1; j < num.size() - 2 ; ++j)
				{
					int vj = num[j];
					if(vj == lastVj)
						continue;
					lastVj = vj;

					int lastVk = num[j + 1] - 1;
					for(int k = j + 1; k < num.size() - 1; ++k)
					{
						int vk = num[k];
						if(vk == lastVk)
							continue;
						lastVk = vk;

						int sum3 = vi + vj + vk;
						int tarVl = target - sum3;
						int si = k + 1, ei = num.size() - 1;
						if(num[si] > tarVl || num[ei] < tarVl)
							continue;
						while(si <= ei)
						{
							int mi = (si + ei) / 2;
							int vl = num[mi];
							if(vl == tarVl)
							{
								vector<int> quad;
								quad.push_back(vi);
								quad.push_back(vj);
								quad.push_back(vk);
								quad.push_back(vl);
								result.push_back(quad);
								break;
							}
							else if(vl > tarVl)
							{
								ei = mi - 1;
							}
							else
							{
								si = mi + 1;
							}
						}

					}
				}
			}
			return result;
		}
};
