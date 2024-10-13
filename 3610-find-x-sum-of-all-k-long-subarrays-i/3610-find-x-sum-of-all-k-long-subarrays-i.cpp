class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x){
        int n=nums.size();
        vector<int> ans;
        for(int i=0; i<= n-k; i++){
            unordered_map<int,int> freq;
            vector<pair<int,int>> freqList;

            for(int j=i; j<i+ k; j++){
                freq[nums[j]]++;
            }
            
            for(auto& [num,count]: freq){
                freqList.push_back({num,count});
            }
            sort(freqList.begin(),freqList.end(),[](const pair<int,int>& a,const pair<int,int>& b){
                if(a.second!=b.second){
                    return a.second>b.second;
                }
                return a.first>b.first;
            });
            int sum=0;
            for(int j=0; j<min(x,(int)freqList.size()); j++){
                sum+= freqList[j].first* freqList[j].second;
            }
            ans.push_back(sum);
        }
        return ans;
    }
};