class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<0){
            return false;
        }
        for(int i=0; i<=31; i++){
            if((1<<i)==n){
                return true;
            }
        }
        return false;

        // int cnt= 0;
        // while(n>0){
        //     if(n&1!= 0){
        //         cnt++;
        //     }
        //     n= n>>1;
        // }
        // return cnt==1;
    }
};