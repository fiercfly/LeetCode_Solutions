class Solution {
public:
    double pwr(double x, int n, double ans){
        if(n<= 0){
            return ans;
        }
        if(n%2==1){
            n--;
            ans= ans*x;
        }
        else{
            n= n/2;
            x*= x;
        }
        return pwr(x, n, ans);
    }
    double myPow(double x, int n) {
        double ans= 1;
        bool fg= true;
        if(x<0){
            if(n%2==0){
                x= abs(x);
            }
            else{
                x= abs(x);
                fg= false;
            }
        }
        if(n<0){
            n= abs(n);
            x= 1/x;
        }
        
        double d= pwr(x,n,ans);
        if(fg== false){
            return -1*d;
        }
        else{
            return d;
        }
    }
};