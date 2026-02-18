class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> plates(n, 0);
        vector<int> leftCandle(n, -1);
        vector<int> rightCandle(n, -1);
 
        plates[0] = (s[0] == '*');
        for (int i = 1; i < n; i++)
            plates[i] = plates[i-1] + (s[i] == '*');
 
        int last = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '|') last = i;
            leftCandle[i] = last;
        }

        last = -1;
        for (int i = n-1; i >= 0; i--) {
            if (s[i] == '|') last = i;
            rightCandle[i] = last;
        }

        vector<int> ans;

        for (auto q : queries) {
            int l = q[0], r = q[1];

            int start = rightCandle[l];
            int end = leftCandle[r];

            if (start == -1 || end == -1 || start >= end) {
                ans.push_back(0);
            } else {
                ans.push_back(plates[end] - plates[start]);
            }
        }

        return ans;
    }
};
