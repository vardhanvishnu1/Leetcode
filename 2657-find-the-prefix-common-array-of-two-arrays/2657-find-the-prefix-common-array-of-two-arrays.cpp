class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int cnt =0;
        vector<int>ans(A.size());
        map<int,int>mp;
        for(int i=0;i<A.size();i++){
            mp[A[i]]++;
            mp[B[i]]++;
            if(A[i]==B[i]){
                if(mp[A[i]]==2) cnt++;
            }
            else{
                if(mp[A[i]]==2) cnt++;
                if(mp[B[i]]==2) cnt++;
            }
            ans[i] = cnt;
        }
        return ans;
    }
};