
auto init = [](){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        int cur = 1;
        while(ans.size() < n){
                if(cur <= n) {
                    ans.push_back(cur);
                    cur = cur * 10;
                }
                else{
                    cur= cur / 10;
                    while(cur%10 == 9){
                        cur= cur/10;
                    }
                    cur++;
                }
        }
        return ans;
    }
};