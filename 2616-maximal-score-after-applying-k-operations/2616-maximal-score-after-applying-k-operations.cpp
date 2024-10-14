class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());

        long long ans= 0;
        while(k--){
            int x= pq.top();
            int red= ceil(x/3.0);
            ans+= x;
            pq.pop();
            pq.push(red);
        }
        return ans;
    }
};