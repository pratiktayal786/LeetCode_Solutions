class Twitter {
public:
    
    unordered_map<int, vector<pair<int,int>>> t;
    unordered_map<int, set<int>> fo;
    long long time;
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        t[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;
        for(auto i : t[userId]){
            pq.push(i);
        }
        for(auto i : fo[userId]){
            for(auto j : t[i]) pq.push(j);
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
            if(ans.size() == 10) break;
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        fo[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        fo[followerId].erase(followeeId);
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