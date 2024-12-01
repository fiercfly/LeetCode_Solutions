class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.rbegin(), arr.rend());
        unordered_map<double, int> mp;

        for(int i: arr){
            double temp=  i/2.0;
            double ele= 2.0*i;
            if(mp.find(ele)!= mp.end() || mp.find(temp)!= mp.end()){
                cout<<ele/2<<" "<<temp<<" "<<endl;
                return true;
            }
            mp[i]++;
        }
        return false;
    }
};