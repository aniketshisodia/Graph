class Solution
{
public:
    bool cycle(int node, int par, vector<int> &vis, vector<vector<int>> &adj)
    {
        vis[node] = 1;
        for (auto adjNode : adj[node])
        {
            if (!vis[adjNode])
            {
                if (cycle(adjNode, node, vis, adj))
                {
                    return true;
                }
            }
            else if (adjNode != par)
                return true;
        }
        return false;
    }

    bool isCycle(vector<vector<int>> &adj)
    {
        vector<int> vis(adj.size(), 0);
        for (int i = 0; i < adj.size(); i++)
        {
            if (vis[i])
                continue;
            if (cycle(i, -1, vis, adj))
            {
                return true;
            }
        }
        return false;
    }
};