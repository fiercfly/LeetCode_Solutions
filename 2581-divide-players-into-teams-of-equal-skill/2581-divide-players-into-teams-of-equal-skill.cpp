class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        long long ans= skill[skill.size()-1]* skill[0];
        int target= skill[skill.size()-1]+ skill[0];
        int i=1;
        int j= skill.size()-2;
        if(skill.size()==2){
            return ans;
        }
        while(i<j){
            if(skill[i]+skill[j] == target){
                ans= ans+ (long)(skill[i]*skill[j]);
            }
            else{
                return -1;
            }
            i++;
            j--;
        }
        return ans;
    }
};

auto init = [](){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
    }();