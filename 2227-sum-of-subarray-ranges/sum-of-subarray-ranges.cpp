class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        // Sum of subarray ranges
// = sum(max contribution) - sum(min contribution)
// Each element contributes:
// value * leftChoices * rightChoices
// Use monotonic stack to find boundaries.

        int n = nums.size();
        long long totalMax = 0, totalMin = 0;
        stack<int> st;

        // ---------- MAX CONTRIBUTION ----------

        vector<long long> leftMax(n), rightMax(n);

        // Previous Greater (strict)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] <= nums[i])
                st.pop();

            leftMax[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Greater (non-strict)
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] < nums[i])
                st.pop();

            rightMax[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = 0; i < n; i++)
            totalMax += nums[i] * leftMax[i] * rightMax[i];

        // ---------- MIN CONTRIBUTION ----------

        vector<long long> leftMin(n), rightMin(n);

        // Previous Smaller (strict)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i])
                st.pop();

            leftMin[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Smaller (non-strict)
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] > nums[i])
                st.pop();

            rightMin[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }

        for (int i = 0; i < n; i++)
            totalMin += nums[i] * leftMin[i] * rightMin[i];

        return totalMax - totalMin;
    }
};