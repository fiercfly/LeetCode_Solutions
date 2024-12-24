class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int totalChange5= 0;
        int totalChange10= 0;
        for(int bill: bills){
            if(bill== 5){
                totalChange5++;
            }
            else if(bill == 10){
                //if we have 5 change
                if(totalChange5>0){
                    totalChange5--;
                    totalChange10++;
                }
                else{
                    return false;
                }
            }
            //if customer give 20
            else{
                //5+ 10
                if(totalChange5>0 && totalChange10>0){
                    totalChange5--;
                    totalChange10--;
                }
                //5+5+5
                else if(totalChange5>=3){
                    totalChange5-=3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};


/*Customer can give 5, 10, 20
Each lemonade= 5
Customer:
    5-> 0
    10-> 5
    20-> 10+5
    20-> 5+5+5
*/