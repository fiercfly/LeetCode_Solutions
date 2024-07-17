class Solution {
public:
    int func(long long ans, string s, int indx, int flag){
        // if(flag*ans>=INT_MAX){
        //     return INT_MAX;
        // }
        // if(flag*ans<=INT_MIN){
        //     return INT_MIN;
        // }
        if(indx == s.length() || !isdigit(s[indx])){
            if(flag*ans>=INT_MAX){
                return INT_MAX;
            }
            else if(flag*ans<=INT_MIN){
                return INT_MIN;
            }
            else{
                return ans*flag;
            }
            
        }
        else if(s[indx] == '-' && indx== 0){
            flag= -1;
        }
        else if (s[indx] == '+' && indx == 0) {
            flag = 1;
        }
        else if(s[indx] != ' ' && isdigit(s[indx])){
            ans*= 10;
            ans= ans+(s[indx]-'0');
            if(flag*ans>=INT_MAX){
                return INT_MAX;
            }
            else if(flag*ans<=INT_MIN){
                return INT_MIN;
            }

            //cout<<ans<<endl;
        }
        else if (s[indx] == ' ' && ans == 0 && indx == 0) {
            return func(ans, s, indx + 1, flag);
        }
        return func(ans, s, indx+1, flag);
    }

    int myAtoi(string s) {
        long long ans= 0;
        int indx= 0;
        int flag= 1;
        while(indx < s.length() && s[indx] == ' '){
            indx++;
        }
        if (indx < s.length() && s[indx] == '-') {
            flag = -1;
            indx++;
        } else if (indx < s.length() && s[indx] == '+') {
            indx++;
        }
        return func(ans,s,indx, flag);
        // return x;
    }
};