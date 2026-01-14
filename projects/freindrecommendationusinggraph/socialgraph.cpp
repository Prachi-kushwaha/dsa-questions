#include "SocialGraph.h"

SocialGraph::SocialGraph(int users) {
    n = users;
    adj.resize(n);
}

void SocialGraph::addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

const vector<int>& SocialGraph::getFriends(int user) const {
    return adj[user];
}

int SocialGraph::size() const {
    return n;
}
