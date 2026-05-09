class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        
        int rows = grid.size();
        int cols = grid[0].size();

        int layers = min(rows, cols) / 2;

        for (int layer = 0; layer < layers; layer++) {

            int top = layer;
            int left = layer;
            int bottom = rows - layer - 1;
            int right = cols - layer - 1;

            vector<int> v;
 
            for (int j = left; j <= right; j++) 
                v.push_back(grid[top][j]);
            
 
            for (int i = top + 1; i <= bottom - 1; i++) 
                v.push_back(grid[i][right]);
            
 
            for (int j = right; j >= left; j--) 
                v.push_back(grid[bottom][j]);
            
 
            for (int i = bottom - 1; i >= top + 1; i--) 
                v.push_back(grid[i][left]);
            

            int sz = v.size();
            int rotateBy = k % sz;

            rotate(v.begin(), v.begin() + rotateBy, v.end());

            int idx = 0;

            for (int j = left; j <= right; j++) 
                grid[top][j] = v[idx++];
            

            for (int i = top + 1; i <= bottom - 1; i++) 
                grid[i][right] = v[idx++];
            
 
            for (int j = right; j >= left; j--) 
                grid[bottom][j] = v[idx++];
            

            // fill left column
            for (int i = bottom - 1; i >= top + 1; i--) 
                grid[i][left] = v[idx++];
            
        }

        return grid;
    }
};