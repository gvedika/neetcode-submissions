class Solution {
public:
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};

    bool valid(int i, int j, int n, int m) {
        return !(i < 0 || i >= n || j < 0 || j >= m);
    }

    int islandPerimeter(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int perimeter = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 1) {

                    perimeter += 4;

                    for (int k = 0; k < 4; k++) {

                        int row = i + x[k];
                        int col = j + y[k];

                        if (valid(row, col, n, m) && grid[row][col] == 1)
                            perimeter--;
                    }
                }
            }
        }

        return perimeter;
    }
};