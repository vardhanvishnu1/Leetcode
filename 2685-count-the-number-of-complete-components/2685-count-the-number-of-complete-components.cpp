#include <vector>

class Solution {
public:
    int countCompleteComponents(int n, std::vector<std::vector<int>>& edges) {
        // Step 1: Build the adjacency list
        std::vector<std::vector<int>> graph(n);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        std::vector<bool> visited(n, false);
        int completeComponents = 0;

        // Step 2: Loop through every node to find unvisited components
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                int vertexCount = 0;
                int totalDegree = 0;

                // Run DFS to populate vertexCount and totalDegree for this component
                dfs(i, graph, visited, vertexCount, totalDegree);

                // Step 3: Verify the complete graph math
                if (totalDegree == vertexCount * (vertexCount - 1)) {
                    completeComponents++;
                }
            }
        }

        return completeComponents;
    }

private:
    void dfs(int node, const std::vector<std::vector<int>>& graph, std::vector<bool>& visited, 
             int& vertexCount, int& totalDegree) {
        
        visited[node] = true;
        vertexCount++;
        totalDegree += graph[node].size(); // Add the number of neighbors for this node

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, graph, visited, vertexCount, totalDegree);
            }
        }
    }
};