class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {
          int n = heights.size();
        vector<int>nse(n);
        vector<int>pse(n);
        stack<int>st;
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
        int ans = 0;
         for (int i = 0; i < n; i++) {
            int width = nse[i] - pse[i] - 1;
            ans = max(ans, width * heights[i]);
        }
        return ans;
    }
};