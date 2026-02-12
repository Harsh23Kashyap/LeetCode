class Solution {
public:

    bool allsame(vector<vector<int>>& grid, int t, int d, int l, int r) {
        int val = grid[t][l];
        for (int i = t; i < d; i++) {
            for (int j = l; j < r; j++) {
                if (grid[i][j] != val)
                    return false;
            }
        }
        return true;
    }

    Node* ans(vector<vector<int>>& grid, int t, int d, int l, int r) {

        if (allsame(grid, t, d, l, r)) 
            return new Node(grid[t][l] == 1, true);

        Node* check = new Node();
        check->isLeaf = false;

        int m1 = t + (d - t) / 2;
        int m2 = l + (r - l) / 2;

        check->topLeft = ans(grid, t, m1, l, m2);
        check->topRight = ans(grid, t, m1, m2, r);
        check->bottomLeft = ans(grid, m1, d, l, m2);
        check->bottomRight = ans(grid, m1, d, m2, r);

        return check;
    }

    Node* construct(vector<vector<int>>& grid) {
        return ans(grid, 0, grid.size(), 0, grid[0].size());
    }
};
