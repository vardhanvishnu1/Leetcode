class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        int n = nums.size();
        vector<int>ans(nums.size());
        for(int j=2*nums.size()-1;j>=0;j--){
                int i = j % n;
            while(!st.empty()&&st.top()<=nums[i]) st.pop();
            if(!st.empty()) ans[i] = st.top();
            else ans[i] = -1;
            st.push(nums[i]);
        }
        return ans;
    }
};
