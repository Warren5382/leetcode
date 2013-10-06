class Solution {
	public:
		int lengthOfLastWord(const char *s) {
			// Note: The Solution object is instantiated only once and is reused by each test case.
			if(s == NULL) return 0;
			int length = strlen(s);
			int count = 0;
			int i = 0;
			for(i=length-1; i >= 0; i--) {
				if((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z')) {
					count++;
					break;
				}
			}
			i--;
			for(; i >= 0; i--) {
				if((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z')) {
					count++;
				}
				else {
					break;
				}
			}
			return count;
		}
};
