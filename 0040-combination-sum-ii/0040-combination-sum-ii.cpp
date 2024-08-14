class Solution {
public:
    void generate(vector<vector<int>> &ans, vector<int> vct, int sum, int sm, int i, vector<int> temp){
        if(sm>= sum){
            if(sm== sum){
                ans.push_back(temp);
            }
            return;
        }

        if(i>= vct.size()){
            return;
        }
        
        temp.push_back(vct[i]);
        generate(ans, vct,sum, sm+ vct[i], i+1, temp);
        
        // sm=sm-vct[i];
        while(i+1<vct.size() && vct[i] == vct[i+1]) {
            i++;
        }
        temp.pop_back();
        generate(ans, vct,sum,sm,i+1, temp);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        generate(ans, candidates, target, 0, 0, {});
        return ans;
    }
};