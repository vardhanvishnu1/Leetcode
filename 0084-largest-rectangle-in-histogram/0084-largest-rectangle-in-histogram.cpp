class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {
          int n = heights.size();
        vector<int>nse(n);
        vector<int>pse(n);
        stack<int>st;
        // next Smaller Element (right)
        for(int i=n-1;i>=0;i--){
            if(st.empty()) {st.push(i);nse[i]=n;continue;}
            while(!st.empty()&&heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()) nse[i] = n;
            else nse[i] = st.top();
            st.push(i);
        }
         while (!st.empty()) st.pop();

        // Previous Smaller Element (Left)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        //The code calculates answer based on both height and width. It doesn't pick one over the other based on height; it calculates the maximum area for every height and then uses max() to see which strategy won.
        int ans = 0;
         for (int i = 0; i < n; i++) {
            int width = nse[i] - pse[i] - 1;
            ans = max(ans, width * heights[i]);
        }
        return ans;
    }
};