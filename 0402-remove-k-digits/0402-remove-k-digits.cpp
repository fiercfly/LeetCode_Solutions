class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> st;
        if(num.length()==1){
            return "0";
        }
        for(char c: num){
            while(!st.empty() && c-'0'<st.top() && k>0){
                st.pop();
                k--;
            }
            st.push(c-'0');
        }
        while(k-- && !st.empty()){
            st.pop();
        }
        if(st.empty()){
            return "0";
        }

        string s="";
        while(!st.empty()){
            s+= to_string(st.top());
            st.pop();
        }
        int ind= s.length()-1;
        while(ind>=1 && s[ind]=='0'){
            ind--;
        }
        string ans= "";
        for(int i=ind; i>=0; i--){
            ans+=s[i];
        }

        return ans;
    }
};