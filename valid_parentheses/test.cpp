class Solution {
	public:
		bool isValid(string s) {
			stack<char> parentheses;
			const char* input = s.c_str();
			int length = s.length();
			for(int i = 0; i < length; i++) {
				if(*input=='(' || *input == '{' || *input == '[') {
					parentheses.push(*input);
				}
				else {
					if(parentheses.size() == 0) return false;
					if(*input == ')' && parentheses.top() != '(') return false;
					if(*input == ']' && parentheses.top() != '[') return false;
					if(*input == '}' && parentheses.top() != '{') return false;
					parentheses.pop();
				}
				input++;
			}
			if(parentheses.size() == 0) return true;
			return false;
		}
};
