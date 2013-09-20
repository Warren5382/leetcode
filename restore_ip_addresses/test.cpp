class Solution {
	public:
		vector<string> restoreIpAddresses(string s) {
			vector<string> result;
			if(s.size() < 4) return result;
			int start[5];//each section start index, last for end
			start[0] = 0;
			start[4] = s.size();
			start[1] = 1;
			int curi = 1;//current dot index, 4 for the one exceed whole ip address
			bool forward = true;
			while(curi > 0) {
				if(forward) {
					//check validation of self
					bool valid = true;
					if(valid) {//check len of section before dot is no more than 3
						int count = start[curi] - start[curi - 1];
						valid = valid && count <= 3;
						if(valid && count > 1) {
							//if the len of section > 1, then the leading digit could not be 0
							valid = s[start[curi - 1]] != '0';
						}
					}
					if(valid) {//check remain digits count validation
						int remain = s.size() - start[curi];
						int remainmax = (4 - curi) * 3;
						valid = valid && remain <= remainmax && remain >= (4 - curi);
					}
					if(valid) {//check section value not exceed 255
						int secvalue = 0;
						for(int i = start[curi - 1]; i < start[curi]; ++i) {
							secvalue *= 10;
							secvalue += (s[i] - '0');
						}
						valid = valid && secvalue <= 255;
					}
					if(valid) {
						if(curi == 4) {
							//this is a valid solution
							string ip = s.substr(start[0],start[1] - start[0]);
							for(int isec = 1; isec < 4; ++isec) {
								ip = ip + '.' + s.substr(start[isec],start[isec + 1] - start[isec]);
							}
							result.push_back(ip);
							--curi;
							forward = false;
						} else {
							//check if there is a child to go
							if(curi == 3) {
								start[curi + 1] = s.size();
							} else {
								start[curi + 1] = start[curi] + 1;
							}
							++curi;
						}
					} else {
						if(curi == 4) {
							curi = 3;
						}
						forward = false;
					}
				} else {
					//backward
					int count = start[curi] - start[curi - 1];
					if (count < 3) {
						++start[curi];
						forward = true;
					} else {
						--curi;
					}
				}
			}//end while
			return result;
		}
};
