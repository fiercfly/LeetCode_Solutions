class Solution {
public:
    int minAddToMakeValid(string s) {
        int open=0;
        int close= 0;
        int req= 0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='('){
                open++;
            }
            else{
                close++;
                if(open>=close){
                    continue;
                }
                else{
                    req++;
                    close--;
                }
            }
        }
        if(open> close){
            req+= open- close;
        }
        return req;
    }
};