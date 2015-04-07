class Solution {
public:
    int rob(vector<int> &num) {
        if (num.size() <= 1) return num.empty() ? 0 : num[0];
        vector<int> dp = {num[0], max(num[0], num[1])};
        for (int i = 2; i < num.size(); ++i) {
            dp.push_back(max(num[i] + dp[i - 2], dp[i - 1]));
        }
        return dp.back();
    }
};
