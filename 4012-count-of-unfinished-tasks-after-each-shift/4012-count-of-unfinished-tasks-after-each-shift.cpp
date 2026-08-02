class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n  = tasks.size();
        int m = shifts.size();
        vector<long long>pre(n,0);
        pre[0] = 1LL*tasks[0];
        for(int i=1;i<n;i++){
            pre[i]+=(pre[i-1]+1LL*tasks[i]);
        }
        vector<int>ans(m);
        long long thr = 0;
        for(int j=0;j<m;j++){
            int lo = 0;
            int hi = n-1;
            int mid ;
            int curr = -1;
            thr+= 1LL*shifts[j];
            while(lo<=hi){
                mid = lo + (hi-lo)/2;
                if(pre[mid]>thr) hi = mid-1;
                else{
                    curr = mid;
                    lo = mid+1;
                }
            }
            int completed ;
            if(curr==-1) completed = 0;
            else completed = curr+1;
            ans[j] = n-completed;
            if(completed==n){
                thr = 0;
            }
        }
        return ans;
    }
};