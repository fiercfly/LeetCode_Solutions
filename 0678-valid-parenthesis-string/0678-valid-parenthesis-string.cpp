class Solution {
public:
    bool checkValidString(string s) {
        int min= 0;
        int max= 0;

        for(char c: s){
            if(c== '('){
                min++;
                max++;
            }
            else if(c== ')'){
                min--;
                max--;
            }
            else{
                min--; // cosider * as close
                max++; //consider * as open
            }
            if(max< 0){
                return false;
            }
            if(min<0){
                min= 0;
            }
        }
        return min==0;
    }
};

/* 
( k liyue ) chaiye
* can be ( ) ""
har ek closing k liye ek opening hona hi chaiye => if closing> opening= false
*/