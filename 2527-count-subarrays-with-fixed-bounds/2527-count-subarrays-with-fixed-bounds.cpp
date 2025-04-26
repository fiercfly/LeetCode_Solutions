

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {

        // std:: cin.tie(0);
        // std:: count.tie(0);


        int ls=0;
        long long cnt= 0;
        int hi= -1,lo= -1;
        int ptr= 0;

        while(ptr < nums.size()){
            if(nums[ptr] < minK || nums[ptr]> maxK){
                ls = ptr+1;
            }

            if(nums[ptr] == minK){
                lo = ptr;
            } //Put the low pointer to place wherer we find minK

            if(nums[ptr] == maxK){
                hi = ptr;
            } //put the high pointer to the point wheere we find maxK

            //count = max(min(high, low: from where the array is starting) - ls+1)

            cnt+= max(min(hi, lo) - ls +1 , 0); 
            // ls can go beyond the starting point of the array so pick the max value bvetween 0 and high,low..

            ptr++;


        }

        return cnt;

    }
};
//  nums: minK maxK
//  bound subarray: minimum = minK maximum= maxK

//  SLiding window

// 2 3 1 3 5 2 7 5
// 1 



// First find a subarray where min= minK and max= maxK
// Then increase the count counting that subarray and keep going for each element incrementing the array untill we get element greater maxK or lesser than minK
// Oncee such element is found, discard the subarray and restart from that index i.e. maxInd= maxK and minInd= minK




// class Solution {
// public:
//     long long countSubarrays(vector<int>& nums, int minK, int maxK) {
//         int mx=0;int ls=0;
//         int low=-1;
//         int high=-1;
//         long long cnt=0;
//         while(mx<nums.size()){
//             if(nums[mx]<minK || nums[mx]>maxK){
//                 //if(nums[low] == minK && nums[high]== maxK){
//                     //cnt += mx-low-2;
//                     ls= mx+1;
//                 }
//             if(nums[mx]== minK){
//                 low= mx;
//             }
//             if(nums[mx]== maxK){
//                 high= mx;
//             }
            
                
//                 cnt+=max((min(low, high)-ls+1),0);

           
//             mx++;

//         }
//         return cnt;
//     }
// };
