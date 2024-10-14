
auto init = [](){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        long long ans= 0;
        while(k--){
            int x= pq.top();
            pq.pop();
            ans+= x;
            pq.push(ceil(x/3.0));;
        }
        return ans;
    }
};