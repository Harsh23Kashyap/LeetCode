class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ops = 0;
        vector<int> st; // monotonic stack

        for (int x : nums) {
            if (x == 0) {
                st.clear(); // reset at zero
                continue;
            }

            // remove larger elements
            while (!st.empty() && st.back() > x)
                st.pop_back();

            // if stack empty or top < x, we start a new "layer"
            if (st.empty() || st.back() < x) {
                st.push_back(x);
                ops++;
            }
        }

        return ops;
    }
};