class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack <int> st;
        int maxi = INT_MIN;
        for (int i = 0; i < heights.size(); i++){
            while (!st.empty() && (heights[st.top()] > heights[i]) ){
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxi = max(maxi, height * width);
            }
            st.push(i);
        }

        while (!st.empty()) {
            int height = heights[st.top()];
            st.pop();
            int width = st.empty() ? heights.size() : heights.size() - st.top() - 1;
            maxi = max(maxi, height * width);
        }
        return maxi;
    }
};