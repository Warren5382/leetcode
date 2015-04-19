class Solution {
public:
    int titleToNumber(string s) {
        int num = 0;
        for (int i = 0; i < s.length(); ++i) {
            num *= 26;
            num += s[i] - 'A' + 1;
        }
        return num;
    }
};
