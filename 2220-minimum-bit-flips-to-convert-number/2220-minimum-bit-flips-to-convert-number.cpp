class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count= 0;
        for(int i=0; i<=31; i++){
            if(((1<<i)&goal) != ((1<<i)&start)){
                count++;
            }
        }
        return count;
    }
};