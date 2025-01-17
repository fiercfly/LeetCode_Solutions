class Solution {
public:
    bool doesValidArrayExist(vector<int>& arr) {
        int n= arr.size();

        vector<int> org(n, 0);

        org[0]= 1;

        for(int i=0; i<n-1; i++){
            if(arr[i] == 1){
                org[i+1]= !org[i];
            }
            else{
                org[i+1]= org[i];
            }
        }

        if(arr[n-1]== 1){
            return org[n-1] == !org[0];
        }
        else{
            return org[n-1] == org[0];
        }

        // 1 0 1
        
    }
};

/*

if arr[0]= 1: 1 0
if arr[i]= 0: i+1=> same as prev
if arr[i]= 1: i+1 => opposite of previous
if arr[n-1]= 0: if arr[0]= same as arr[n-1] true else false
if arr[n-1]= 1: if arr[0]= opposite of arr[n-1] true else false

*/