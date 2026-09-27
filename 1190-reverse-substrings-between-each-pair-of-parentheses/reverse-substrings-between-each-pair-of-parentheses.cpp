class Solution {
public:
    string reverseParentheses(string s) {
        string ans;
        stack<int> starts;
        for (char c : s) {
            if (c == '(') starts.push(ans.size());
            else if (c == ')') {
                int start = starts.top();
                starts.pop();
                reverse(ans.begin() + start, ans.end());
            } else ans += c;
        }
        return ans;
    }
};
