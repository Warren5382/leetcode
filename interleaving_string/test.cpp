class Solution {
	public:
		bool isInterleave(string s1, string s2, string s3) {
			if(s3.size() != s1.size() + s2.size())
				return false;
			//create indicator
			vector<vector<bool> > match(s1.size() + 1, vector<bool>(s2.size() + 1, false));
			//initialization the first row and the first column
			match[0][0] = true;
			for( int l1 = 1; l1 <= s1.size(); ++ l1 ) {
				char c1 = s1[l1 - 1];
				char c3 = s3[l1 - 1];
				if (c1 == c3) {
					match[l1][0] = true;
				} else 
					break;
			}
			for( int l2 = 1; l2 <= s2.size(); ++ l2 ) {
				char c2 = s2[l2 - 1];
				char c3 = s3[l2 - 1];
				if (c2 == c3) {
					match[0][l2] = true;
				} else 
					break;
			}
			//work through the rest of matrix using the formula
			for( int l1 = 1; l1 <= s1.size(); ++ l1 ) {
				char c1 = s1[l1 - 1];
				for( int l2 = 1 ; l2 <= s2.size() ; ++ l2 ) {
					char c2 = s2[l2 - 1];
					int l3 = l1 + l2;
					char c3 = s3[l3 - 1];
					if (c1 == c3) {
						match[l1][l2] = match[l1 - 1][l2] || match[l1][l2];
					}
					if (c2 == c3) {
						match[l1][l2] = match[l1][l2 - 1] || match[l1][l2];
					}
				}
			}
			//the last element is the result
			return match[s1.size()][s2.size()];
		}
};
