// jai shree ram

/*    0 → 1 → 2 → 3
              ↓   ↑
              4 → 5
*/

class Solution {
public:
    bool cycle(int node, vector<int> &vis, vector<int> &recStack, vector<vector<int>> &adj) {
        vis[node] = 1;
        recStack[node] = 1;

        for (auto adjNode : adj[node]) {
            if (!vis[adjNode]) {
                if (cycle(adjNode, vis, recStack, adj)) {
                    return true;
                }
            } else if (recStack[adjNode]) { 
                return true; // Cycle detected
            }
        }

        recStack[node] = 0; // Remove from recursion stack before returning
        return false;
    }

    bool isCyclic(vector<vector<int>> &adj) {
        int n = adj.size();
        vector<int> vis(n, 0);
        vector<int> recStack(n, 0);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (cycle(i, vis, recStack, adj)) {
                    return true;
                }
            }
        }
        return false;
    }
};
