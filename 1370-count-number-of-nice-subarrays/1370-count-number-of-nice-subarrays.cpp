
auto init = [](){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int left= 0;
        int right= 0;
        int count= 0;
        int ans= 0;
        int odd= 0;
        while(right< nums.size()){
            if(nums[right]%2== 1){
                count= 0;
                odd++;
            }
            while(odd== k){
                if(nums[left]%2 == 1){
                    odd--;
                }
                count++;
                left++;
            }  
            ans+= count;
            right++;

        }
        return ans;
    }
};