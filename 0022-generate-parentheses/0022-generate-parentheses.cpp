class Solution {
public:
    void generator(int lk, int rk, int n, string s, vector<string> &ans){
        if(lk==n && rk== n){
            ans.push_back(s);
            return;
        }
        if(lk<n){
            generator(lk+1, rk, n, s+'(', ans);
        }
        if(rk<lk){
            generator(lk, rk+1, n,s+')',ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generator(0,0,n,"",ans);
        return ans;
    }
};