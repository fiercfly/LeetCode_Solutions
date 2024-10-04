class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            if(!dq.empty() && dq.front()== i-k){
                dq.pop_front();
            }

            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }

            dq.push_back(i);

            if(i>=k-1){
                ans.push_back(nums[dq.front()]);
            }

        }
        return ans;
        
    }
};

auto init = [](){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();