
auto init = [](){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
class Solution {
public:
    static bool cmp(int a, int b){
        string s= to_string(a);
        string s2= to_string(b);
        return s+s2>s2+s;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        string s= "";
        for(int i: nums){
            s+= to_string(i);
        }
        if(s[0]== '0'){
            return "0";
        }
        return s;
    }
};