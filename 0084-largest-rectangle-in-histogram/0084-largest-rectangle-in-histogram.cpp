class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        stack<int>st;
        vector<int>nse(n);
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                st.push(i);nse[i] = n;continue;
            }
            while(!st.empty()&&heights[i]<=heights[st.top()]){
                st.pop();
            }
            if(st.empty()) nse[i] = n;
            else nse[i] = st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        vector<int>pse(n);
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(i);pse[i] = -1;continue;
            }
            while(!st.empty()&&heights[i]<=heights[st.top()]){
                st.pop();
            }
            if(st.empty()) pse[i] = -1;
            else pse[i] = st.top();
            st.push(i);
        }
        for(int i=0;i<n;i++){
            ans = max(ans,(nse[i]-pse[i]-1)*(heights[i]));
        }
        return ans;
    }
};