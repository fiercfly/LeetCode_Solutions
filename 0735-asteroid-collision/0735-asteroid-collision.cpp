class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i: asteroids){
            bool broke= false;
            // if(!st.empty()){
                //stack ka top pos h and num neg h
                while(!st.empty()&& st.top()>0 &&  i<0){
                    if(abs(st.top())< abs(i)){
                        cout<<"k";
                        st.pop();
                    }
                    else if(abs(st.top()) == abs(i)){
                        st.pop();
                        broke= true;
                        break;
                    }
                    else{
                        broke= true;
                        break;
                    }
                }
            if(!broke){
                st.push(i);
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};