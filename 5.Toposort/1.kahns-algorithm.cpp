// jai shree ram

// kahn's algorithm
class Solution
{
public:
    vector<int> topologicalSort(vector<vector<int>> &adj)
    {

        int n = adj.size();

        vector<int> ind(n, 0);

        for (int i = 0; i < n; i++)
        {
            for (auto node : adj[i])
            {
                ind[node]++;
            }
        }

        vector<int> ans;

        queue<int> q;

        for (int i = 0; i < n; i++)
        {
            if (ind[i] == 0)
            {
                q.push(i);
            }
        }

        while (q.size())
        {
            int node = q.front();
            ans.push_back(node);
            q.pop();

            for (auto adjNode : adj[node])
            {
                ind[adjNode]--;
                if (!ind[adjNode])
                {
                    q.push(adjNode);
                }
            }
        }

        return ans;
    }
};
