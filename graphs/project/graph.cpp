#include "graph.h"

Graph::Graph(int v) {
    V = v;
    adj.resize(V);
}

void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool isCycleDetect(int node, int parent, vector<int>& visited, vector<vector<int>>& adj) {
    visited[node] = 1;
    for (int n : adj[node]) {
        if (!visited[n]) {
            if (isCycleDetect(n, node, visited, adj))
                return true;
        } else if (n != parent) {
            return true;
        }
    }
    return false;
}

bool Graph::isCycle() {
    vector<int> visited(V, 0);
    for (int i = 0; i < V; i++) {
        if (!visited[i] && isCycleDetect(i, -1, visited, adj))
            return true;
    }
    return false;
}
