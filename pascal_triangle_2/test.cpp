class Solution {
	public:
		vector<int> getRow(int rowIndex) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			vector<int> ret;
			if(rowIndex < 0) return ret;
			for(int ir = 0; ir <= rowIndex; ir++) {
				ret.push_back(1);
				for(int ic = ir-1; ic > 0; ic--) {
					ret[ic]=ret[ic]+ret[ic-1];
				}
			}
			return ret;
		}
};
