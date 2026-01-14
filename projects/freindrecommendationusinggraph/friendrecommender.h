#ifndef FRIEND_RECOMMENDER_H
#define FRIEND_RECOMMENDER_H

#include "socialgraph.h"
#include <vector>

class FriendRecommender {
public:
    vector<int> recommend(const SocialGraph& graph, int user);
};

#endif
