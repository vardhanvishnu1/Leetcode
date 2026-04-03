class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        int n = nums.size();
        vector<int>left(n);
        vector<int>right(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&nums[st.top()]>=nums[i]) st.pop();
            if(!st.empty()) left[i] = i-st.top();
            else left[i] = i+1;
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&nums[st.top()]>nums[i]) st.pop();
            if(st.empty()) right[i] = n-i;
            else right[i] = st.top()-i;
            st.push(i);
        }
        long long ans =0;
        for(int i=0;i<n;i++){
            long long count = (long long)left[i]*right[i];
            ans = (ans + (((count%1000000007)*nums[i])%1000000007))%1000000007;
        }
        return (int)ans;
    }
};