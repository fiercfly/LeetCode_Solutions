class Solution {
public:
    double myPow(double x, int n) {
        bool flag= true;
        if(n<0){
            n= abs(n);
            x= 1/x;
        }
        if(x<0){
            if(n%2!=0){
                flag= false;
            }
            x= abs(x);
        }

        double result= 1;
        double base= x;
        while(n> 0){
            if(n%2== 1){
                result*= base;
            }
            base*= base;
            n/= 2;
        }

        if(flag== false){
            return -result;
        }
        return result;
    }
};