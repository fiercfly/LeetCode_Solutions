class Twitter {
public:
    long long time = 0;
    unordered_map<int, set<int>> following; //whom the user follows
    unordered_map<int, vector<pair<int, int>>> tweets; //time, tweetId

    Twitter() {
        time= 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time, tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue<pair<int,int>> pq;
        for(auto it: tweets[userId]){ //its a pair: time, tweetId
            pq.push(it); 
        }
        for(int f: following[userId]){ //f is a follower
            for(auto it: tweets[f]){//again a pair: time, tweetId
                pq.push(it);
            }
        }

        while(!pq.empty()  && res.size()< 10){
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
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