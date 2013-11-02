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

class Solution {
	public:
		vector<int> twoSum(vector<int> &numbers, int target) {
			// IMPORTANT: Please reset any member data you declared, as
			// the same Solution instance will be reused for each test case.
			unordered_map<int, int> index_map;
			unordered_map<int, int>::iterator it;
			vector<int> result;
			for (int i=0; i<numbers.size(); ++i) {
				it = index_map.find(target-numbers[i]);
				if (it != index_map.end()) {
					result[0] = it->second;
					result[1] = i+1;
					return result;
				} else {
					index_map[numbers[i]] = i+1;
				}
			}
			return result;
		}
};
