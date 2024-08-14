class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int low= 0;
        int high= nums[nums.size()-1]- nums[0];
        // int j=0;
        while(low<high){
            int mid=(low+high)/2;
            int cnt= 0;
            int j=0;
            for(int i=0;i<nums.size(); i++){
                while(j<nums.size() && nums[j]-nums[i]<=mid){
                    j++;
                }
                cnt+= j-i-1;
            }
            // if(cnt==k){
            //     return mid;
            // }

            if(cnt>=k){
                high= mid;
            }
            else{
                low= mid+1;
            }
        }
        return low;
    }
};