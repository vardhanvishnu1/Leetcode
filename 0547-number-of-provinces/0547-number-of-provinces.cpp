 
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<bool>& visited, int node) {
        visited[node] = true;
        int n = graph.size();
        for (int neighbor = 0; neighbor < n; neighbor++) {
            if (graph[node][neighbor] == 1 && !visited[neighbor]) {
                dfs(graph, visited, neighbor);
            }
        }
    }

    int countComponents(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visited(n, false);
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(graph, visited, i);
                components++;
            }
        }
        return components;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        return countComponents(isConnected);
    }
};
