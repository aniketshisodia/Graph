// jai shree ram
class Solution
{
public:
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src)
    {

        int n = adj.size();

        vector<int> dist(n, 1e5);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, src});

        vector<int> vis(n, 0);

        dist[src] = 0;

        // vis[src] = 1;

        while (pq.size())
        {

            auto tt = pq.top();

            int node = tt.second;

            int dis = tt.first;

            pq.pop();

            if (vis[node])
                continue;

            vis[node] = 1;

            for (auto it : adj[node])
            {

                int edgeWt = it.second;

                int adjNode = it.first;

                if (dist[adjNode] > edgeWt + dis)
                {

                    dist[adjNode] = edgeWt + dis;

                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
};