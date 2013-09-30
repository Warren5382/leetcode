class Solution {
	public:
		string simplifyPath(string path) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			vector<string> pathes;
			string seg = "";
			for(int i = 0; i <= path.size(); ++i) {
				if(i == path.size() || path[i] == '/') {
					if(seg == "..") {
						if(pathes.size() > 0) {
							pathes.pop_back();
						} else {
							//return "/";//error, in the test set, this case just ignore
						}
					} else if(seg == ".") {
						//do nothing
					} else if(seg.size() > 0) {
						pathes.push_back(seg);
					}
					seg = "";
				} else {
					seg += path[i];
				}
			}
			string ret="/";
			for(int i = 0; i < pathes.size(); ++i) {
				if(i>0) ret += "/";
				ret += pathes[i];
			}
			return ret;
		}
};
