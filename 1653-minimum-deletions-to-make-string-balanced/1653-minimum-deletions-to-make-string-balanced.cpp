class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.length();
        vector<int>cnta(n+1,0), cntb(n+1,0);
        for(int i=0;i<n;i++){
            cnta[i+1]=cnta[i]+(s[i]=='a');
        }
        for(int i=n-1;i>=0;i--){
            cntb[i]=cntb[i+1]+(s[i]=='b');
        }
        
        int minDelete=INT_MAX;
        for(int i=0;i<n+1;i++){
            minDelete=min(minDelete,n-cnta[i]-cntb[i]);
        }
        return minDelete;
    }
};