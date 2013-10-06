class Solution {
	public:
		void calcallpermutation (vector<int> &num, int first, int length, vector<vector<int>> &result) {
			if(length <= 1) {
				result.push_back(num);
				return;
			}
			char temp = 'a';
			for(int i = first; i < first+length; i++) {
				temp = num[i];
				num[i] = num[first];
				num[first] = temp;
				calcallpermutation(num, first+1, length-1, result);
				temp = num[i];
				num[i] = num[first];
				num[first] = temp;
			}
		}
		vector<vector<int> > permute(vector<int> &num) {
			// Note: The Solution object is instantiated only once and is reused by each test case.
			vector<vector<int>> result;
			if(num.size() <= 1) {
				result.push_back(num);
			} 
			else {
				calcallpermutation(num, 0, num.size(), result);
			}
			return result;
		}
};
