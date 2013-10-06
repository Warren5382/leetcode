class Solution {
	static bool earlier(const Interval &int0, const Interval &int1) {
		return int0.start < int1.start;
	}
	public:
	vector<Interval> merge(vector<Interval> &intervals) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(intervals.size() <= 1) return intervals;
		sort(intervals.begin(),intervals.end(),Solution::earlier);
		vector<Interval> ret;
		Interval openInt = intervals[0];
		for(int i = 0; i < intervals.size(); ++i) {
			Interval &cur = intervals[i];
			if(openInt.end < cur.start) {
				ret.push_back(openInt);
				openInt = cur;
			} else {
				if (openInt.end < cur.end) openInt.end = cur.end;
			}
		}
		ret.push_back(openInt);
		return ret;
	}
};
