class Solution {
	public:
		vector<vector<int> > generate(int numRows) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			vector<vector<int> >ret;
			if(numRows == 0) return ret;
			//first row
			ret.push_back(vector<int>(1,1));
			//rest rows;
			for(int nr = 2; nr <= numRows; ++nr) {
				vector<int> thisrow(nr,1);
				vector<int> &lastrow = ret[nr-2];
				for(int ic = 1; ic < nr - 1; ++ic) {
					thisrow[ic] = lastrow[ic-1] + lastrow[ic];
				}
				ret.push_back(thisrow);
			}
			return ret;
		}
};
