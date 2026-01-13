#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int v);
    void addEdge(int u, int v);
    bool isCycle();
};

#endif
