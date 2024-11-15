class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i: nums){
            mp[i]++;
        }
        
        priority_queue<pair<int, int>> pq;
        for(auto i: mp){
            pq.push({i.second, i.first});
        }

        for(int i=0; i<k; i++){
            pair<int , int> temp= pq.top();
            pq.pop();
            ans.push_back(temp.second);
        }
        return ans;
    }
};