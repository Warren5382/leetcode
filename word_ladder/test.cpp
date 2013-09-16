class Solution {
	public:
		struct state{
			string str;
			int counter;
			state():str(""),counter(0){};
		};
		int ladderLength(string start, string end, unordered_set<string> &dict) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			queue<state> que;
			state now;
			state next;
			now.str = start;
			que.push(now);
			while(!que.empty()) {
				now = que.front();
				if(now.str == end) {
					return now.counter+1;
				}
				for(int i = 0; i < now.str.length(); i++) {
					for(char j = 'a'; j <= 'z'; j++) {
						if(now.str[i] == j) {
							continue;
						}
						next.str = now.str;
						next.str[i] = j;
						if(dict.count(next.str) > 0) {
							next.counter = now.counter+1;
							que.push(next);
							dict.erase(next.str);
						}
					}
				}
				que.pop();
			}
			return 0;
		};
};
