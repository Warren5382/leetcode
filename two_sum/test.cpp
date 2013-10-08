class Solution {
	public:
		vector<int> twoSum(vector<int> &numbers, int target) {
			vector<int> ret;
			int length = numbers.size();
			if(length <= 1) return ret;
			//find min/max for trim
			sort(numbers.begin(), numbers.end());
			int front = 0;
			int back = length-1;
			int sum = 0;
			while(front < back) {
				sum = numbers[front]+numbers[back];
				if(sum < target) front++;
				else if(sum > target) back--;
				else {
					break;
				}
			}
			ret.push_back(front+1);
			ret.push_back(back+1);
			return ret;
		}
};
