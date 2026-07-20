class Solution {
public:

    vector<int> parent;
    vector<int> size;

    int find(int node)
    {
        if(parent[node] == node)
            return node;

        return parent[node] = find(parent[node]);
    }

    void Union(int u, int v)
    {
        int pu = find(u);
        int pv = find(v);

        if(pu == pv)
            return;

        if(size[pu] < size[pv])
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for(int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }

        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            if(find(u) == find(v))
            {
                return {u, v};
            }

            Union(u, v);
        }

        return {};
    }
};