class Solution {
public:
    int maxWidthRamp(vector<int>& nums){
        vector<int> st;
        int maxi = 0;
        for(int i=0; i<nums.size(); i++){
            if(st.empty() || nums[st.back()]>nums[i]){
                st.push_back(i);
            }
        }

        for(int j=nums.size()-1; j>= 0; j--){
            while(!st.empty() && nums[st.back()]<= nums[j]){
                maxi= max(maxi, j- st.back());
                st.pop_back();
            }
        }
        return maxi;

    }
};


// 43333333333333300
// stack:
// 0
// 1
// 2
// 3
// 4

// 6
// 7
// 8
// 9



