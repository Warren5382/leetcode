class Solution {
	public:
		int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
			// Note: The Solution object is instantiated only once and is reused by each test case.
			int length = gas.size();
			if(length <= 0) return 0;

			vector<int> cap(length, 0);
			int sum = 0;
			for(int i = 0; i < length; i++) {
				cap[i] = gas[i]-cost[i];
				sum += cap[i];
			}
			if(sum < 0) return -1;
			int step = 0;
			int k = 0;
			for(int i = 0; i < length; i++) {
				step = 0;
				sum = 0;
				while(step < length) {
					k = (i+step)%length;
					sum += cap[k];
					if(sum < 0) {
						break;
					}
					else {
						step++;
					}
				}
				if(step == length) return i;
				else {
					i = k;
				}
			}
			return -1;
		}
};
