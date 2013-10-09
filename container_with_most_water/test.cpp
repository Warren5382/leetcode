class Solution {
	public:
		int maxArea(vector<int> &height) {
			// Note: The Solution object is instantiated only once and is reused by each test case.
			if(height.size() < 2) return 0;
			int i = 0;
			int j = height.size()-1;
			int area = 0;
			int maxarea = 0;
			while(i < j) {
				area = min(height[i], height[j])*(j-i);
				if(area > maxarea) maxarea = area;
				if(height[i] > height[j]) j--;
				else i++;
			}
			return maxarea;
		}
};
