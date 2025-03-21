// jai shree ram

/*

Bellman-Ford Algorithm - Key Points
✅ Purpose: Finds the shortest path from a single source to all vertices, even with negative weight edges.
✅ Time Complexity: 
𝑂
(
𝑉
𝐸
)
O(VE), where 
𝑉
V = vertices, 
𝐸
E = edges.
✅ Steps:

Initialize all distances as infinity (1e9), except the source (0).
Relax all edges 
𝑉
−
1
V−1 times:
If dist[v] > dist[u] + w, update dist[v].
Detect negative cycles by checking if we can still update any edge.
Why Run Bellman-Ford 
𝑉
−
1
V−1 Times?
📌 A shortest path in a graph has at most 
𝑉
−
1
V−1 edges (in a connected graph).
📌 After 
𝑉
−
1
V−1 relaxations, all shortest paths must be finalized.
📌 The extra check detects negative weight cycles—if any edge can still be updated, a cycle exists. 

*/

class Solution {
  public:
    
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
       
        int n = V;
        
        vector<int> dist(n , 1e8);
        
        dist[src] = 0;
        
        for(int i = 0 ; i < n-1 ; i++) {
            
            for(auto it : edges) {
                
                int u = it[0];
                
                int v = it[1];
                
                int w = it[2];
                
                if(dist[u] != 1e8 && dist[v] > dist[u] + w) {
                    
                    dist[v] = dist[u] + w;
                    
                }
                
            }
            
        }
        
        for(auto it : edges) {
                
            int u = it[0];
                
            int v = it[1];
                
            int w = it[2];
                
            if(dist[v] > dist[u] + w && dist[u] != 1e8)  {
                    
                return {-1};
                    
            }
                
        }
        return dist;
    }
};

