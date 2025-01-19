class Solution {
public:
    bool dfs(unordered_set<int>& v, unordered_set<int>& u, vector<int>& vis, vector<vector<int>>& graph, int ind) {
        if (vis[ind]) { 
            return true; // Node is already visited, no conflict
        }

        vis[ind] = 1;
        v.insert(ind); // Mark the node as visited and add to the current set
        
        for (auto neighbor : graph[ind]) {
            if (v.count(neighbor) > 0) { 
                return false; // Found a conflict (same set)
            }
            if (u.count(neighbor) == 0) { 
                if (!dfs(u, v, vis, graph, neighbor)) { 
                    return false; // Propagate failure upwards
                }
            }
        }
        
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        unordered_set<int> v; // One set
        unordered_set<int> u; // Opposite set
        vector<int> vis(graph.size(), 0); // Visited array

        for (int i = 0; i < graph.size(); i++) {
            if (!vis[i]) { 
                if (!dfs(v, u, vis, graph, i)) { 
                    return false; // If any component is not bipartite
                }
            }
            // Swap sets for the next unconnected component
            swap(v, u);
        }
        
        return true;
    }
};
