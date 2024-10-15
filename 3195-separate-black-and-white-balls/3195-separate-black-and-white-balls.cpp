class Solution {
public:
    long long minimumSteps(string s) {
        long long swaps= 0;
        int curr= 0;
        for(int i=0; i<s.length(); i++){
            if(s[i]== '0'){
                //previously how many 1s have been there contibuting in each swap
                swaps+= i-curr;
                curr++;
            }
        }
        return swaps;

    }
};