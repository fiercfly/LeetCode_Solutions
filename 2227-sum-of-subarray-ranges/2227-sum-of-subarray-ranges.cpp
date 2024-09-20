class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        vector<int> nextg(nums.size(),0);
        vector<int> prevg( nums.size(),0);
        vector<int> nexts(nums.size(),0);
        vector<int> prevs(nums.size(),0);

        //prevs
        stack<int> st;
        for(int i=0; i<nums.size(); i++){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(!st.empty()){
                prevs[i]= st.top();
            }
            else{
                prevs[i]= -1;
            }
            st.push(i);
        }

        //nextg
        stack<int> st2;
        for(int i=nums.size()-1; i>= 0; i--){
            while(!st2.empty() && nums[st2.top()]<nums[i]){
                st2.pop();
            }
            if(!st2.empty()){
                nextg[i]= st2.top();
            }
            else{
                nextg[i]= nums.size();
            }
            st2.push(i);
        }

        //nexts
        stack<int> st3;
        for(int i= nums.size()-1; i>= 0; i--){
            while(!st3.empty() && nums[st3.top()]>nums[i]){
                st3.pop();
            }
            if(!st3.empty()){
                nexts[i]= st3.top();
            }
            else{
                nexts[i]= nums.size();
            }
            st3.push(i);
        }

        //prevg
        stack<int> st4;
        for(int i=0; i<nums.size(); i++){
            while(!st4.empty() && nums[st4.top()]<=nums[i]){
                st4.pop();
            }
            if(!st4.empty()){
                prevg[i]= st4.top();
            }
            else{
                prevg[i]= -1;
            }
            st4.push(i);
        }

        //calculation
        long long ans= 0;
        long long gr= 0;
        long long sm= 0;
        for(int i=0; i<nums.size(); i++){
            gr=gr+( (long)nums[i]* (i-prevg[i])* (long)(nextg[i]-i));
        }
        for(int i=0; i<nums.size(); i++){
            sm= sm+((long)nums[i]* (prevs[i]-i)*(long)(i-nexts[i]));
        } 

        ans= gr-sm;
        return ans;

    }
};