#include <iostream>
#include "socialgraph.h"
#include "friendrecommender.h"

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    SocialGraph graph(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }

    int user;
    cin >> user;

    FriendRecommender recommender;
    vector<int> recommendations = recommender.recommend(graph, user);

    cout << "Recommended friends: ";
    for (int x : recommendations) {
        cout << x << " ";
    }

    return 0;
}
