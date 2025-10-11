class Solution {
public:
    void NSE(int n,vector<int>&nse,vector<int>& arr){
        stack<int>st;
        nse[n-1]=n;
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!st.empty()&&(arr[i]<=arr[st.top()])){
                st.pop();
            }
            if(st.empty()){
                nse[i]=n;
            }
            else nse[i]=st.top();
            st.push(i);
        }
    }
    void PSE(int n,vector<int>&pse,vector<int>& arr){
       stack<int> st;
for(int i = 0; i < n; i++) {
    while (!st.empty() && arr[st.top()] > arr[i]) {
        st.pop();
    }
    pse[i] = st.empty() ? -1 : st.top();
    st.push(i);
}
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int>nse(n);
        vector<int>pse(n);
        NSE(n,nse,arr);
        PSE(n,pse,arr);
        long long  ans = 0;
        for(int i=0;i<n;i++){
            ans = (ans+1LL*(nse[i]-i)*(i-pse[i])*arr[i])%1000000007;
        }
        return ans;
    }
};