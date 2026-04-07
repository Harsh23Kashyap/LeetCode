class Solution {
public:
    Node* build(vector<vector<int>>& grid, int r, int c, int size) { 
        bool same = true;
        int val = grid[r][c];

        for (int i = r; i < r + size; i++) {
            for (int j = c; j < c + size; j++) {
                if (grid[i][j] != val) {
                    same = false;
                    break;
                }
            }
            if (!same) break;
        }
 
        if (same) 
            return new Node(val, true);
        
 
        int half = size / 2;

        Node* topLeft = build(grid, r, c, half);
        Node* topRight = build(grid, r, c + half, half);
        Node* bottomLeft = build(grid, r + half, c, half);
        Node* bottomRight = build(grid, r + half, c + half, half);

        return new Node(1, false, topLeft, topRight, bottomLeft, bottomRight);
    }

    Node* construct(vector<vector<int>>& grid) {
        return build(grid, 0, 0, grid.size());
    }
};