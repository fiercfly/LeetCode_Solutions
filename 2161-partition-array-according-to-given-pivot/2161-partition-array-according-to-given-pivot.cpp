class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> x,y,z;
        for (int i: nums){
            if (i< pivot){
                x.push_back(i);
            } 
            else if (i> pivot){
                z.push_back(i);
            } else y.push_back(i);
        }
        x.insert(x.end(), y.begin(), y.end());
        x.insert(x.end(), z.begin(), z.end());
        return x;
    }
};