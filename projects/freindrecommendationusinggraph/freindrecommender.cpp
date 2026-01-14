#include "FriendRecommender.h"
#include <unordered_map>
#include <algorithm>

vector<int> FriendRecommender::recommend(const SocialGraph& graph, int user) {
    int n = graph.size();
    vector<bool> isFriend(n, false);

    for (int f : graph.getFriends(user)) {
        isFriend[f] = true;
    }

    unordered_map<int, int> mutualCount;

    for (int f : graph.getFriends(user)) {
        for (int fof : graph.getFriends(f)) {
            if (fof != user && !isFriend[fof]) {
                mutualCount[fof]++;
            }
        }
    }

    int maxCount = 0;
    for (auto &p : mutualCount) {
        maxCount = max(maxCount, p.second);
    }

    vector<int> result;
    for (auto &p : mutualCount) {
        if (p.second == maxCount) {
            result.push_back(p.first);
        }
    }

    return result;
}
