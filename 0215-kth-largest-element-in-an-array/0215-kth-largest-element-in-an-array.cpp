
auto init = [](){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

//Quick Sort approach
class Solution {
public:
    int partition(vector<int>& arr, int left, int right) {
        int pivot = arr[left] ;
        int l = left + 1 ;
        int r = right;
        while (l <= r) {
            if (arr[l] < pivot && arr[r] > pivot) {
                swap(arr[l], arr[r]);
                l++ ;
                r-- ;
            }
            if (arr[l] >= pivot) {
                l++;
            }
            if (arr[r] <= pivot) {
                r--;
            }
        }
        swap(arr[left], arr[r]);
        return r;
    }

    int findKthLargest(vector<int>& arr, int k) {
        int left = 0, right = arr.size() - 1, kth;
        while (1) {
            int idx = partition(arr, left, right);
            if(idx== k- 1) {
                kth = arr[idx];
                break;
            }
            if(idx < k - 1) {
                left = idx + 1;
            } else {
                right = idx - 1;
            }
        }
        return kth;
    }
};


//Priority Queue Approach

// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         priority_queue<int> pq;
//         for(int i=0; i<nums.size(); i++){
//             pq.push(nums[i]);
//         }
//         for(int i=0; i<k-1; i++){
//             pq.pop();
//         }
//         return pq.top();
//     }
// };


