class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int MOD= 1e9+7;
        int ans= 0;
        vector<int> psml(arr.size());
        vector<int> nsml(arr.size());
        stack<int> st;
        //psml ko fill crow
        for(int i=0; i<arr.size(); i++){
            while(!st.empty()&& arr[i]<=arr[st.top()]){
                st.pop();
            }
            if(st.empty()){
                psml[i]= -1;
            }
            else{
                psml[i]= st.top();
            }
            st.push(i);
        }


        //stack khali crow
        while(!st.empty())st.pop();

        //nsml ko fill crow
        for(int i=arr.size()-1; i>=0; i--){
            while(!st.empty()&& arr[i]<arr[st.top()]){
                st.pop();
            }
            if(st.empty()){
                nsml[i]= arr.size();
            }
            else{
                nsml[i]= st.top();
            }
            st.push(i);
        }

        for(int i: nsml){
            cout<<i<<endl;
        }for(int i: psml){
            cout<<i<<endl;
        }
        for(int i=0; i<arr.size(); i++){
        ans = (ans + (long long)arr[i] * (i - psml[i]) * (nsml[i] - i) % MOD) % MOD;
        }

        return ans;



        
    }
};