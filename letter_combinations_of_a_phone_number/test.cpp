class Solution {
	public:
		void DFS(vector<vector<char>> &map, vector<string> &result, string &temp, const char* number) {
			if(*number == 0) {
				result.push_back(temp);
				return;
			}
			if(*number < '0' || *number > '9') {
				DFS(map, result, temp, number++);
			}
			else {
				int len = map[*number-48].size();
				for(int i = 0;i < len;i++) {
					temp.push_back(map[*number-48][i]);
					DFS(map, result, temp, number+1);
					temp.pop_back();
				}
			}
		}
		vector<string> letterCombinations(string digits) {
			vector<vector<char> >map(10);
			map[0] = vector<char>(1);

			map[0][0] = ' ';
			map[1] = vector<char>(1);
			map[1][0] = ' ';

			map[2] = vector<char>(3);
			map[2][0] = 'a';
			map[2][1] = 'b';
			map[2][2] = 'c';

			map[3] = vector<char>(3);
			map[3][0] = 'd';
			map[3][1] = 'e';
			map[3][2] = 'f';

			map[4] = vector<char>(3);
			map[4][0] = 'g';
			map[4][1] = 'h';
			map[4][2] = 'i';

			map[5] = vector<char>(3);
			map[5][0] = 'j';
			map[5][1] = 'k';
			map[5][2] = 'l';

			map[6] = vector<char>(3);
			map[6][0] = 'm';
			map[6][1] = 'n';
			map[6][2] = 'o';

			map[7] = vector<char>(4);
			map[7][0] = 'p';
			map[7][1] = 'q';
			map[7][2] = 'r';
			map[7][3] = 's';

			map[8] = vector<char>(3);
			map[8][0] = 't';
			map[8][1] = 'u';
			map[8][2] = 'v';

			map[9] = vector<char>(4);
			map[9][0] = 'w';
			map[9][1] = 'x';
			map[9][2] = 'y';
			map[9][3] = 'z';

			const char* number = digits.c_str();

			vector<string> result;
			string temp="";
			DFS(map, result, temp, number);
			return result;
		}
};
