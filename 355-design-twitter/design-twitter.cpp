class Twitter {
public:
 int timestamp;
    unordered_map<int, unordered_set<int>> followers;
    unordered_map<int, vector<pair<int, int>>> tweets; // userId -> list of (timestamp, tweetId)

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
            followers[userId].insert(userId);
        tweets[userId].push_back({timestamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        if (followers.find(userId)==followers.end())
        return {};

        priority_queue<tuple<int, int, int, int>> pq;
    
        for (int followeeId : followers[userId]) {
            if (tweets.count(followeeId) && !tweets[followeeId].empty()) {
                int lastIdx = tweets[followeeId].size() - 1;
                auto [time, tweetId] = tweets[followeeId][lastIdx];
                pq.emplace(time, tweetId, lastIdx, followeeId);
            }
        }
    

        vector<int> res;
        int c = 0;

        while (!pq.empty() && c < 10) {
            auto [time, tweetId, idx, uid] = pq.top(); pq.pop();
            res.push_back(tweetId);
            c++;

            if (idx > 0) {
                auto [nextTime, nextTweetId] = tweets[uid][idx - 1];
                pq.emplace(nextTime, nextTweetId, idx - 1, uid);
            }
        }

        return res;
}
    
    void follow(int followerId, int followeeId) {
        followers[followeeId].insert(followeeId); 
        followers[followerId].insert(followeeId);
        followers[followerId].insert(followerId); 
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followers.find(followerId)!=followers.end()){
            followers[followerId].erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */