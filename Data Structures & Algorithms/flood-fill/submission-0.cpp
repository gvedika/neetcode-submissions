class Solution {
public:
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};

    bool valid(int i, int j, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m)
            return false;
        return true;
    }

    void dfs(vector<vector<int>>& image, int i, int j, int n, int m,
             int original, int color) {

        // Stop if outside the grid
        if (!valid(i, j, n, m))
            return;

        // Stop if this cell is not the original color
        if (image[i][j] != original)
            return;

        // Fill the current cell
        image[i][j] = color;

        // Visit all 4 neighbours
        for (int k = 0; k < 4; k++) {
            int row = i + x[k];
            int col = j + y[k];

            dfs(image, row, col, n, m, original, color);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int color) {

        int n = image.size();
        int m = image[0].size();

        int original = image[sr][sc];

        // Important edge case
        if (original == color)
            return image;

        dfs(image, sr, sc, n, m, original, color);

        return image;
    }
};