#include <bits/stdc++.h>
using namespace std;

int main() {
    // n = users, m = friendships
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int user;
    cin >> user;

    vector<bool> isFriend(n, false);
    for (int f : graph[user]) {
        isFriend[f] = true;
    }

    unordered_map<int, int> mutualCount;

    // Count mutual friends
    for (int f : graph[user]) {
        for (int fof : graph[f]) {
            if (fof != user && !isFriend[fof]) {
                mutualCount[fof]++;
            }
        }
    }

    // Find max mutual friends
    int maxCount = 0;
    for (auto &p : mutualCount) {
        maxCount = max(maxCount, p.second);
    }

    cout << "Recommended friends: ";
    for (auto &p : mutualCount) {
        if (p.second == maxCount) {
            cout << p.first << " ";
        }
    }

    return 0;
}
