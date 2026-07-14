class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& vis, int city) {
        vis[city] = true;

        // Traverse all neighbors of the current city
        for (int neighbor = 0; neighbor < isConnected.size(); neighbor++) {
            if (isConnected[city][neighbor] == 1 && !vis[neighbor]) {
                dfs(isConnected, vis, neighbor);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<bool> vis(n, false);
        int province = 0;

        // Visit every city
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(isConnected, vis, i);
                province++;
            }
        }

        return province;
    }
};