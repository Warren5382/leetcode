class Solution {
	public:
		vector<int> spiralOrder(vector<vector<int> > &matrix) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			vector<int> arr;
			int rows = matrix.size();
			if(0 == rows) return arr;
			int cols = matrix[0].size();
			if(0 == cols) return arr;
			int bri = 0, bci = 0;//short for base row index, base column index
			while(rows > 0 && cols > 0) {
				//add a spiral circle based at bri and bci in matrix
				if(rows == 1) {
					for(int ci = bci; ci < bci + cols; ++ ci) {
						arr.push_back(matrix[bri][ci]);
					}
					break;
				} else if (cols == 1) {
					for(int ri = bri; ri < bri + rows; ++ri) {
						arr.push_back(matrix[ri][bci]);
					}
					break;
				}
				//rows >= 2 and cols >= 2, a circle well formed
				//top
				for(int ci = bci; ci < bci + cols; ++ci) {
					arr.push_back(matrix[bri][ci]);
				}
				//right
				for(int ri = bri + 1; ri < bri + rows; ++ri) {
					arr.push_back(matrix[ri][bci + cols - 1]);
				}
				//bottom
				for(int ci = bci + cols - 2; ci >= bci; --ci) {
					arr.push_back(matrix[bri + rows - 1][ci]);
				}
				//left
				for(int ri = bri + rows - 2; ri > bri; --ri) {
					arr.push_back(matrix[ri][bci]);
				}
				rows -= 2;
				cols -= 2;
				bri += 1;
				bci += 1;
			}//end while
			return arr;
		}
};
