class Solution {
public:
    int minOperations(vector<string>& logs) {
        // int deep= 0;
        stack<string> st;
        bool empty= true;
        for(string cmd: logs){
            if(st.size() == 0){
                empty= true;
            }
            if(cmd== "./"){
                continue;
            }
            else if(cmd== "../"){
                if(empty== false){
                    st.pop();
                    
                }
                else{
                    continue;
                }  
            }
            else{
                st.push("cmd");
                empty= false;
            }
        }
        cout<<st.size();
        return st.size();
    }
};