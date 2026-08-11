// class Solution {
// public:
//     int missingInteger(vector<int>& nums) {
//         int maxP= nums[0];
//         int curP= nums[0];
//         int maxL= 1;
//         int curL= 1;
//         unordered_map<int,int> mp;
//         mp[nums[0]]++;

//         for(int i=1; i<nums.size(); i++){
//             mp[nums[i]]++;
//             if(nums[i] != nums[i-1]+1){
//                 maxL= max(maxL, curL);
//                 maxP= max(maxP, curP);
//                 curP= nums[i];
//                 curL=1;
//             }
//             else{
//                 curP+= nums[i];
//                 curL++;
//             }
//         }
//         maxL= max(maxL, curL);
//         maxP= max(maxP, curP);

//         while(mp.find(maxP) != mp.end()){
//             // cout<<maxP<<endl;
//             maxP++;
//         }
//         return maxP;
//     }
// };





class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } else {
                break;
            }
        }

        unordered_set<int> seen(nums.begin(), nums.end());

        int answer = sum;

        while (seen.count(answer)) {
            answer++;
        }

        return answer;
    }
};