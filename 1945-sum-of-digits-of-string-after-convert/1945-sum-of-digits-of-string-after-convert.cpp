class Solution {
public:
   long long transform(long long x){
        long long ans= 0;
        while(x>0){
            ans= (ans+x%10);
            x= x/10;
        }
        return ans;
    }

    long long stringTointeger(string p){
        long long ans= 0;
        for(char c: p){
            ans= (ans+(c-'0'));
        }
        return ans;
    }


    int getLucky(string s, int k) {
        string changed= "";
        for(char c: s){
            int x= c-'a'+1;
            changed+= to_string(x);
        }
        long long ans= stringTointeger(changed);
        for(int i=1; i<k; i++){
            ans= transform(ans);
        }
        return (int) ans;
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();