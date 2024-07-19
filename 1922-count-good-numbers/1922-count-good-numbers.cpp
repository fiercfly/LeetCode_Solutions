class Solution {
public:
long long cnt(long long n,int fg, long long &ans){
    if(n==0){
        return ans;
    }
    if(fg== 1){
        // ans*= 5;
        ans=(ans*5)%1000000007;
    }
    else{
        ans=(ans*4)%1000000007;
        // ans%1000000007;
    }
    n--;
    fg= 1-fg;
    return cnt(n,fg, ans);
}

long long power(long long n, long long ans, long long x){
    if(n<=0){
        return ans;
    }
    if(n%2 == 1){
        ans=(ans* x)%1000000007;
        n--;
    }
    else{
        x=(x*x)%1000000007;
        n= n/2;
    }
    return power(n,ans,x);
    
}
    int countGoodNumbers(long long n) {
        bool fg= true;
        long long ans= 1;
        if(n%2== 1){
            fg=false;
            n--;
        }
        ans= (power(n/2, ans,5))%1000000007;
        ans=(power(n/2, ans,4))%1000000007;
        if(fg){
            return ans;
        }
        else{
            return (5*ans)%1000000007;
        }
        

        
    }
};