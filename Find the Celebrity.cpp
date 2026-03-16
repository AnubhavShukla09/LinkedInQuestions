class Solution {
public:
    int findCelebrity(int n) {
        int left = 0, right = n - 1;
        // Step 1: find potential celebrity
        while (left < right) {
            if (knows(left, right)) {
                left++; // left cannot be celebrity
            } else {
                right--; // right cannot be celebrity
            }
        }
        int candidate = left;
        // Step 2: verify candidate
        for (int i = 0; i < n; i++) {
            if (i == candidate)
                continue;
            // candidate should not know anyone
            // everyone should know candidate
            if (knows(candidate, i) || !knows(i, candidate)) {
                return -1;
            }
        }
        return candidate;
    }
};
// if a know b - a cannot be celebrity
// if a does not know b - b cannot be celebrity
