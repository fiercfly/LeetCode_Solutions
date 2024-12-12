class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long ans= 0;
        priority_queue<int> q;
        for(int i: gifts){
            q.push(i);
        }
        while(!q.empty() && k--){
            int gift= q.top();
            q.pop();
            q.push(sqrt(gift));
        }

        while(!q.empty()){
            ans=ans+ q.top();
            q.pop();
        }
        return ans;
    }
};