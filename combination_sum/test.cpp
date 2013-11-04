class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> r;

        if (target == 0) {
            return r;
        }

        for (int i=candidates.size()-1; i>=0; i--) {
            if (candidates[i] < target) {
                vector<vector<int>> t = this->combinationSum(candidates, target - candidates[i]);
                for (int j=0; j<t.size(); j++) {
                    vector<int> tmp = t[j];
                    if (tmp.size() == 0 || candidates[i] >= tmp.back()) {
                        tmp.push_back(candidates[i]);
                        r.push_back(tmp);
                    }
                }
            } else if (candidates[i] == target) {
                vector<int> s;
                s.push_back(target);
                r.push_back(s);
            }
        }

        return r;

    }
};