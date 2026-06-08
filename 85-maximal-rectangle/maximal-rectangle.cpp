class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
                if (matrix.empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> heights(n, 0);
        int maxArea = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') heights[j]++;
                else heights[j] = 0;
            }
            
            stack<int> s;
            for (int j = 0; j <= n; j++) {
                int h = (j == n) ? 0 : heights[j];
                while (!s.empty() && h < heights[s.top()]) {
                    int height = heights[s.top()];
                    s.pop();
                    int width = s.empty() ? j : j - s.top() - 1;
                    maxArea = max(maxArea, height * width);
                }
                s.push(j);
            }
        }
        return maxArea;
    }
};