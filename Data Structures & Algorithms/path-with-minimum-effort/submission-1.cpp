class Solution {
public:
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};

    bool valid(int i, int j, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m)
            return false;
        return true;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {

            pair<int, pair<int,int>> p = pq.top();
            pq.pop();

            int effort = p.first;
            int row = p.second.first;
            int col = p.second.second;

            if (effort > dist[row][col])
                continue;

            if (row == n - 1 && col == m - 1)
                return effort;

            for (int k = 0; k < 4; k++) {

                int nr = row + x[k];
                int nc = col + y[k];

                if (valid(nr, nc, n, m)) {

                    int wt = abs(heights[row][col] - heights[nr][nc]);

                    int newEffort = max(effort, wt);

                    if (newEffort < dist[nr][nc]) {

                        dist[nr][nc] = newEffort;

                        pq.push({newEffort, {nr, nc}});
                    }
                }
            }
        }

        return 0;
    }
};