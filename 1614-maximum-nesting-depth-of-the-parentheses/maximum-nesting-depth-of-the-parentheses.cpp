class Solution {
public:
    int maxDepth(string s) {
        int d = 0, best = 0;
        for (char c : s) {
            if (c == '(') best = max(best, ++d);
            else if (c == ')') --d;
        }
        return best;
    }
};
