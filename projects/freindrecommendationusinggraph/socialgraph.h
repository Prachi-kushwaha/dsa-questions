#ifndef SOCIAL_GRAPH_H
#define SOCIAL_GRAPH_H

#include <vector>
using namespace std;

class SocialGraph {
private:
    int n;
    vector<vector<int>> adj;

public:
    SocialGraph(int users);

    void addEdge(int u, int v);

    const vector<int>& getFriends(int user) const;

    int size() const;
};

#endif
