class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int layers = min(m, n) / 2;

        for (int l = 0; l < layers; l++) {
            vector<int> vals;
            int top = l, left = l;
            int bottom = m - l - 1, right = n - l - 1;

            // top row
            for (int j = left; j < right; j++)
                vals.push_back(grid[top][j]);
            // right col
            for (int i = top; i < bottom; i++)
                vals.push_back(grid[i][right]);
            // bottom row
            for (int j = right; j > left; j--)
                vals.push_back(grid[bottom][j]);
            // left col
            for (int i = bottom; i > top; i--)
                vals.push_back(grid[i][left]);

            int len = vals.size();
            int shift = k % len;
            rotate(vals.begin(), vals.begin() + shift, vals.end());

            int idx = 0;
            // put back
            for (int j = left; j < right; j++)
                grid[top][j] = vals[idx++];
            for (int i = top; i < bottom; i++)
                grid[i][right] = vals[idx++];
            for (int j = right; j > left; j--)
                grid[bottom][j] = vals[idx++];
            for (int i = bottom; i > top; i--)
                grid[i][left] = vals[idx++];
        }
        return grid;
    }
};