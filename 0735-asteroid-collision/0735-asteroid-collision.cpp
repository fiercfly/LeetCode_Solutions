class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        
        for(int i : asteroids) {
            bool broke = false;
            
            // Process only when stack has a positive asteroid and current one is negative
            while(!st.empty() && st.top() > 0 && i < 0) {
                if(abs(st.top()) < abs(i)) {
                    // Current asteroid is larger, pop the stack and continue
                    st.pop();
                } else if(abs(st.top()) == abs(i)) {
                    // They are equal, both are destroyed
                    st.pop();
                    broke = true;
                    break;
                } else {
                    // Stack top is larger, current asteroid is destroyed
                    broke = true;
                    break;
                }
            }
            
            // If the current asteroid was not destroyed, push it to the stack
            if(!broke) {
                st.push(i);
            }
        }
        
        // Collect remaining asteroids from stack
        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(), ans.end()); // Reverse to maintain original order
        return ans;
    }
};
