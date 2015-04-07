class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if (n < 1) {
            return 0;
        }
        int start = 0;
        int end = n - 1;
        while (start <= end) {
            int index = (end + start) / 2;
            if (A[index] >= target) {
                end = index - 1;
            } else {
                start = index + 1;
            }
        }
        return start;
    }
};
