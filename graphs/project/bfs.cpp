#include<iostream>
#include "graph.h"
using namespace std;

int main() {
    int vertex, edges;
    cin >> vertex >> edges;

    Graph g(vertex);
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    cout << (g.isCycle() ? "Cycle\n" : "No Cycle\n");
}
